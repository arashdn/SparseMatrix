#include "Cell.h"


Cell::Cell(int r , int c , int v)
{
	setCell(r,c,v);
}

Cell::Cell()
{

}

int Cell::getRow()
{
	return row;
}


int Cell::getCol()
{
	return col;
}

int Cell::getValue()
{
	return value;
}

void Cell::setCell(int r , int c , int v)
{
	row = r;
	col = c;
	value = v;
}

void Cell::setRow(int r)
{
	row = r;
}

void Cell::setCol(int c)
{
	col = c;
}

void Cell::setValue(int v)
{
	value = v;
}