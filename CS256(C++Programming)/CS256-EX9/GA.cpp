// Andrew Trang
// Example 9
// Completed 1/15/2016

#include "Chromosome.h"
#include <stdlib.h>

Chromosome randomChromosome(int size) {
	std::ostringstream sout;
	for (int i = 0; i < size; i++)
		sout << (char) ((rand() % 26) + 97);
	return Chromosome(sout.str());
}

Chromosome runGA(std::string target, int popSize, double mr, double cr) {
	std::vector<Chromosome> population;
	std::vector<Chromosome> newGeneration;
	int iteration = 0;
	int index;
	for (int i = 0; i < popSize; ++i)
		population.push_back(randomChromosome(target.length()));
	while (population[0].fitness(target) != 0) {
		for (int i = 0; i < popSize * 2; ++i) {
			index = rand() % popSize;
			newGeneration.push_back(population[index]);
			if (rand() % 100 <= mr*100)
				newGeneration[i] = newGeneration[i].mutate();
			if (rand() % 100 <= cr*100)
				newGeneration[i] = newGeneration[i].crossover(population[rand() % popSize]);
			newGeneration[i].fitness(target);
		}
		std::sort (newGeneration.begin(), newGeneration.end(), [=] (Chromosome a, Chromosome b) { return a.fitness(target) < b.fitness(target); });
		std::cout << "Iteration " << ++iteration << std::endl << "Best: " << newGeneration[0].getData() << std::endl;
		newGeneration.erase (newGeneration.begin() + popSize, newGeneration.end());
		population.clear();
		population = newGeneration;
		newGeneration.clear();
	}
	return population[0];
}

int main(int argc, char **argv) {
	srand(time(0));
	std::string target = argv[1];
	int popSize = atoi(argv[2]);
	double mr = atof(argv[3]);
	double cr = atof(argv[4]);
	Chromosome answer = runGA(target, popSize, mr, cr);
	std::cout << "Solution found: " << answer << std::endl;
	std::cin.get();
}