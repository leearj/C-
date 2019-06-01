#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Game.h"

Game::Game() : width(DEFAULT_WIDTH), height(DEFAULT_HEIGHT), start(0), last(0), current(0), good(true), running(false), particles(std::vector<Particle>()) {
	// Seed the random number generator
	srand(time(0));

	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		good = false;
		return;
	}

	// initialize SDL window
	window = SDL_CreateWindow("Gravity", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		good = false;
		return;
	}

	// initialize SDL renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		good = false;
		return;
	}

	// initialize particle texture
	SDL_Surface* bmp = SDL_LoadBMP("particle.bmp");
	if (bmp == NULL) {
		good = false;
		return;
	}
	particleTexture = SDL_CreateTextureFromSurface(renderer, bmp);
	SDL_FreeSurface(bmp);
	if (particleTexture == NULL) {
		good = false;
		return;
	}

	// initialize our particles
	for (int i = 0; i < PARTICLE_COUNT; ++i) {
		particles.push_back(randomParticle());
	}
}

Game::~Game() {
	if (!good) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
	}
	if (particleTexture != NULL) {
		SDL_DestroyTexture(particleTexture);
	}
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
	}
	if (window != NULL) {
		SDL_DestroyWindow(window);
	}
	SDL_Quit();
}

int Game::operator()() {
	if (!good) {
		return -1;
	}
	running = true;
	SDL_Event event;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	start = SDL_GetTicks();
	last = start;

	while (running) { // every iteration is 1 frame
		current = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			handleEvent(event);
		}
		update((current - last) / 1000.0);
		render();
		last = current;
	}

	return 0;
}

// dt is time since last frame in seconds
void Game::update(double dt) {
	std::cout << dt << " sec since last frame.\n";

	//boolean 2d array : isColliding
	bool isColliding[PARTICLE_COUNT][PARTICLE_COUNT];
	for (int i = 0; i < particles.size(); ++i) {
		for (int j = 0; j < particles.size(); ++j) {
			isColliding[i][j] = false;
		}
	}

	
	//Collision handling
	for (int i = 0; i < particles.size(); ++i) {
		for (int j = 0; j < particles.size(); ++j) {
			if (i != j) {
				if (collide(particles[i], particles[j])) {
					if (!isColliding[i][j])
						collisionHelper(particles[i], particles[j], dt);
					isColliding[i][j] = true;
					isColliding[j][i] = true;
				}
			}
		}
	}

	//Velocity Handler
	for (int j = 0; j < particles.size(); ++j) {
		//Border Check
		if (particles[j].getPos().getX()+particles[j].getRadius() >= width || particles[j].getPos().getX()-particles[j].getRadius() <= 0){
			particles[j].setPos((particles[j].getRadius()),particles[j].getPos().getY());
			particles[j].getVel().getX() *= -1;
		}

		if (particles[j].getPos().getY()+particles[j].getRadius() >= width || particles[j].getPos().getY()-particles[j].getRadius() <= 0){
			particles[j].setPos(particles[j].getPos().getX(),(particles[j].getRadius()));			
			particles[j].getVel().getY() *= -1;
		}

		particles[j].getPos().getX() += particles[j].getVel().getX() * dt;
		particles[j].getPos().getY() += particles[j].getVel().getY() * dt;
	}

	//Acceleration by Gravity
	for (int i = 0; i < particles.size(); ++i) {
		double m1 = particles[i].getMass();
		for (int j = 0; j < particles.size(); ++j) {
			if (i != j && !isColliding[i][j]) {
				double m2 = particles[j].getMass();
				//Distance formula below
				double dist = sqrt(pow(particles[j].getPos().getX() - particles[i].getPos().getX(), 2) + pow(particles[j].getPos().getY() - particles[i].getPos().getY(), 2));
				double gForce = G * (m1*m2) / (dist* dist);

				double gAcceleration = gForce / m1;
				particles[j].getVel().getX() += -(particles[j].getPos().getX() - particles[i].getPos().getX()) * gAcceleration * dt;
				particles[j].getVel().getY() += -(particles[j].getPos().getY() - particles[i].getPos().getY()) * gAcceleration * dt;
			}
		}
	}
}

//Extra function1: collisionHelper
void Game::collisionHelper(Particle& ball1, Particle& ball2, double dt) {
	double m1 = ball1.getMass();
	double m2 = ball2.getMass();

	double x1 = ball1.getPos().getX();
	double y1 = ball1.getPos().getY();

	double x2 = ball2.getPos().getX();
	double y2 = ball2.getPos().getY();

	double vx1 = ball1.getVel().getX();
	double vy1 = ball1.getVel().getY();

	double vx2 = ball2.getVel().getX();
	double vy2 = ball2.getVel().getY();

	double v1 = sqrt((vx1 * vx1) + (vy1 * vy1));
	double v2 = sqrt((vx2 * vx2) + (vy2 * vy2));

	double a1 = atan2(vy1, vx1);
	double a2 = atan2(vy2, vx2);

	double angleOfCollision = atan2(y2 - y1, x2 - x1);

	double nvx1 = cos(angleOfCollision) * (v1 * cos(a1 - angleOfCollision) * (m1 - m2) + 2 * m2*v2*cos(a2 - angleOfCollision)) / (m1 + m2) + v1*sin(a1 - angleOfCollision) * cos(angleOfCollision + (PI / 2));
	double nvy1 = sin(angleOfCollision) * (v1 * cos(a1 - angleOfCollision) * (m1 - m2) + 2 * m2*v2*cos(a2 - angleOfCollision)) / (m1 + m2) + v1*sin(a1 - angleOfCollision) * sin(angleOfCollision + (PI / 2));

	angleOfCollision += PI;

	double nvx2 = cos(angleOfCollision) * (v1 * cos(a1 - angleOfCollision) * (m1 - m2) + 2 * m2*v2*cos(a2 - angleOfCollision)) / (m1 + m2) + v1*sin(a1 - angleOfCollision) * cos(angleOfCollision + (PI / 2));
	double nvy2 = sin(angleOfCollision) * (v1 * cos(a1 - angleOfCollision) * (m1 - m2) + 2 * m2*v2*cos(a2 - angleOfCollision)) / (m1 + m2) + v1*sin(a1 - angleOfCollision) * sin(angleOfCollision + (PI / 2));

	ball1.getVel().getX() = nvx1;
	ball1.getVel().getY() = nvy1;

	ball2.getVel().getX() = nvx2;
	ball2.getVel().getY() = nvy2;
}

//Extra function2: collide
bool Game::collide(Particle& ball1, Particle& ball2) {
	float dist = sqrt(pow(ball2.getPos().getX() - ball1.getPos().getX(), 2) + pow(ball2.getPos().getY() - ball1.getPos().getY(), 2));
	float sumRadius = ball2.getRadius() + ball1.getRadius();

	if (dist <= sumRadius) return true;
	else return false;
}



void Game::render()
{
	SDL_RenderClear(renderer);

	// rendering here would place objects beneath the particles

	for (Particle& p : particles) {
		drawParticle(p);
	}

	// rendering here would place objects on top of the particles

	SDL_RenderPresent(renderer);
}

void Game::handleEvent(const SDL_Event& event){
	switch (event.type) {
		// Add your own event handling here if desired
	case SDL_QUIT:
		running = false;
		break;
	default:
		break;
	}
}

void Game::drawParticle(Particle& p) {
	SDL_Rect dst;
	double shift = p.getRadius();
	dst.x = (int)(p.getPos().getX() - shift);
	dst.y = (int)(p.getPos().getY() - shift);
	dst.w = shift * 2;
	dst.h = shift * 2;
	SDL_RenderCopy(renderer, particleTexture, NULL, &dst);
}

Particle Game::randomParticle() const {
	Point pos(rand() % width, rand() % height);

	// using random percentage of MAX_MASS
	double mass = ((double)rand() / RAND_MAX) * MAX_MASS + 1.0;

	return Particle(pos, mass);
}
