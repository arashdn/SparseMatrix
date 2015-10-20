#pragma once
#include <iostream>
#include "Cell.h"
class Sparse
{

	friend std::ostream & operator <<(std::ostream& os, Sparse &sprc);

	Cell * cells;
	int row;
	int col;
	int value;


public:
	Sparse(int ** a , int r, int c);
	Sparse(Sparse &  a );

	Sparse (int r , int c , int val);

	~Sparse(void);

	int getRow();
	int getCol();
	int getValue();

	void setRow(int r);
	void setCol(int c);
	void setValue(int v);

	int getRowX(int i);
	int getRowY(int i);
	int getRowValue(int i);


	Sparse operator+ (Sparse sp2);
	Sparse operator* (Sparse sp2);
	int findInRows(int i);
	int findInCols(int i,int loc );

	Sparse transpose();

	Sparse quickTranspose();
};

