#include"2DMatrix.h"
#include<iostream>
#include<iomanip>

Matrix_2D::Matrix_2D(int row, int col, bool auto_full){
	this -> row = row;
	this -> column = col;

	array = new double* [row];
	for (int i = 0; i < row; i++)
		array[i] = new double[col];

	if(!auto_full)
		Init();
	else
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				array[i][j] = 0;
}

bool Matrix_2D::Init(){
	cout<<"请输入"<<row<<"*"<<column<<"的矩阵："<<endl;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			cin>>array[i][j];

	return true;
}

bool Matrix_2D::Show(){
	cout<<"矩阵为："<<endl;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++)
			cout<<setw(8)<<array[i][j]<<'\t';
		cout<<endl<<endl;
	}

	return true;
}

int Matrix_2D::getrow(){ return row; }
int Matrix_2D::getcolumn(){ return column; }
