#include "Sparce.h"
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


	Sparce mySparce(a,row,col);
	Sparce mySparce2(a,row,col);
	
	//Sparce b = mySparce + mySparce2;
	cout << "Sparce1: \n" << mySparce;
	cout << "\nSparce2: \n" << mySparce2 << endl<<"Sparce 1+2:\n";
	cout << mySparce + mySparce2 ;
	cout <<"\nTranspose:\n" << mySparce.transpose();
	cout <<"\nQuick Transpose:\n" << mySparce.quickTranspose();
	cout<<"\nSparce 1*2:\n";
	cout << mySparce * mySparce2 ;
	cin.ignore();
	cin.get();
	return 0;
}