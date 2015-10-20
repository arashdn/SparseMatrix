#pragma once
#include <iostream>
#include "Cell.h"
class Sparce
{

	friend std::ostream & operator <<(std::ostream& os, Sparce &sprc);

	Cell * cells;
	int row;
	int col;
	int value;


public:
	Sparce(int ** a , int r, int c);
	Sparce(Sparce &  a );

	Sparce (int r , int c , int val);

	~Sparce(void);

	int getRow();
	int getCol();
	int getValue();

	void setRow(int r);
	void setCol(int c);
	void setValue(int v);

	int getRowX(int i);
	int getRowY(int i);
	int getRowValue(int i);


	Sparce operator+ (Sparce sp2);
	Sparce operator* (Sparce sp2);
	int findInRows(int i);
	int findInCols(int i,int loc );

	Sparce transpose();

	Sparce quickTranspose();
};

