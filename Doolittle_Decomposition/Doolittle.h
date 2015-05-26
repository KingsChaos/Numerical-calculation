#ifndef DOOLITTLE_H
#define DOOLITTLE_H

#include"2DMatrix.h"
using namespace std;


class Doolittle{
public:
	Doolittle(){}
	Doolittle(int row, int col);
	bool Decomposition();
	bool Calculation();
	bool ShowResult();
private:
	Matrix_2D Matrix;                 //线性方程组系数矩阵
	Matrix_2D L;                      //分解后的下三角矩阵
	Matrix_2D U;					  //分解后的上三角矩阵
	double *X;                        //线性方程组的解
	double *Y;						  //线性方程组右侧数组
};

#endif
