#include"Guass.h"
#include<cmath>
#include <iomanip>
#include<iostream>

Guass::Guass(){

	cout<<"请输入矩阵维数："<<endl;
	cin>> row;
	cout<<endl;

	cout<<"请输入eps："<<endl;
	cin>>eps;
	cout<<endl;

	this -> X = new double [row];

	this -> Array = new double* [row];
	for (int i = 0; i < row; i++)
		Array[i] = new double [ row + 1 ];
	
	cout<<"请输入矩阵："<<endl;

	for (int i = 0; i < row; i++)
		for (int j = 0; j <  row + 1 ; j++)
			cin>>Array[i][j];

	cout<<endl;
}

Guass::~Guass(){
	delete []X;

	for (int i = 0; i < row; i++)
		delete []Array[i];
	delete []Array;
}

bool Guass::Exchange(int i, int j){
	double *tmp = new double[ row + 1 ];

	for (int m = 0; m < row + 1; m++){
		tmp[m] = Array[i][m];
		Array[i][m] = Array[j][m];
		Array[j][m] = tmp[m];
	}

	return true;
}

bool Guass::SelctMaj(int k){
	double max;
	int col;

	max = fabs( Array[ k - 1 ][ k - 1 ] );
	col = k - 1;
	for (int i = k - 1; i < row ; i++){
		double t = fabs (Array[ k - 1 ][i] );
		if( t > max ){
			max = t;
			col = i;
		}
	}

	if(max < eps)
		return false;

	Exchange( k - 1, col );

	return true;
}

bool Guass::Elimination(){
	for(int step = 1; step < row; step++){

		if(!SelctMaj(step))
			return false;

		for (int i = step; i < row; i++){                                       //第k步消元，需要从第k行计算到最后一行

			if(Array[step - 1][step - 1] == 0)
				return false;

			double m = Array[i][step - 1] / Array[step - 1][step - 1];          //m为每行与主行第一个非0元素的倍数
			for (int j = step - 1; j < row + 1; j++){
				Array[i][j] -=  Array[step - 1][j] * m;
			}
		}
	}
	return true;
}

bool Guass::Compute(){

	for (int i = row - 1; i >= 0 ; i--){
		double sum = 0;
		for (int j = row - 1; j > i; j--)
			sum += X[j] * Array[i][j];

		X[i] = ( Array[i][row] - sum ) / Array[i][i];
	}

	return true;
}

bool Guass::Show(){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < row + 1; j++)
			cout<<setw(8)<<Array[i][j]<<'\t';
		cout<<'\n'<<'\n';
	}

	return true;
}

bool Guass::ShowX(){
	for (int i = 0; i < row ; i++)
		cout<<setw(8)<<X[i]<<'\t';

	return true;
}

bool Guass::Start(){

	cout<<"初始矩阵："<<endl<<endl;
	Show();

	cout<<"开始消元..."<<endl<<endl;

	if(!Elimination()){
		cout<<"无解！"<<endl<<endl;
		return false;
	}

	cout<<"消元之后的矩阵："<<endl<<endl;
	Show();

	cout<<"开始回代求解..."<<endl<<endl;

	if(!Compute()){
		cout<<"无解！"<<endl<<endl;
		return false;
	}

	cout<<"计算结果："<<endl<<endl;
	ShowX();

	cout<<endl<<endl;

	return true;
}





