#pragma once
class Cell
{
public:
	Cell(int r , int c , int v);
	Cell();

	int getRow();
	int getCol();
	int getValue();

	void setCell(int r , int c , int v);
	void setRow(int r);
	void setCol(int c);
	void setValue(int v);

private:
	int row;
	int col;
	int value;
};

