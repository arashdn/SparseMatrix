#include "Sparse.h"
#include <iostream>
using namespace std;



int main()
{
	int row = 4 , col = 4;
	int ** a = new int*[row];
	for (int i = 0; i < row; i++)
		a[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = 0;


	a[0][2] = 5;
	a[3][1] = 2;
	a[1][3] = 1;


	Sparse mySparse(a,row,col);
	Sparse mySparse2(a,row,col);
	
	//Sparse b = mySparse + mySparse2;
	cout << "Sparse1: \n" << mySparse;
	cout << "\nSparse2: \n" << mySparse2 << endl<<"Sparse 1+2:\n";
	cout << mySparse + mySparse2 ;
	cout <<"\nTranspose:\n" << mySparse.transpose();
	cout <<"\nQuick Transpose:\n" << mySparse.quickTranspose();
	cout<<"\nSparse 1*2:\n";
	cout << mySparse * mySparse2 ;
	cin.ignore();
	cin.get();
	return 0;
}