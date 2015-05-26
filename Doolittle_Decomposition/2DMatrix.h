#ifndef MATRIX2D_H
#define MATRIX2D_H

#include<iostream>
#include<iomanip>

using namespace std;

class Matrix_2D{
public:
	Matrix_2D(){}
	Matrix_2D(int row, int col, bool auto_full = true);
	bool Init();
	bool Show();
	int getrow();
	int getcolumn();

	double **array;
private:
	int row;
	int column;
};

#endif