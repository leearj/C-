//Lee Jaeseung
//EX7
//Completed on 2016-02-24

#ifndef CONWAY_H
#define CONWAY_H

#include <string>

class Conway
{
private:
	bool **board;
	int rows,cols;
	
public:
	Conway();
	Conway(const std::string filename);
	Conway(const Conway& other);
	~Conway();
	void operator=(const Conway& other);
	bool alive(int row, int col);
	void flip(int row, int col);
	std::string str() const;
	void step();
	void play(int n);
};

#endif