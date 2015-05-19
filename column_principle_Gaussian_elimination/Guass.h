#ifndef GUASS_H
#define GUASS_H

#include<iostream>

using namespace std;

class Guass{

public:
	Guass();
	~Guass();
	bool SelctMaj(int k);                     //选取第k步的主元
	bool Exchange(int i, int j);              //交换第i行和第j行
	bool Elimination();                       //消元
	bool Compute();                           //求解
	bool Show();                              //显示矩阵
	bool ShowX();                             //显示结果
	bool Start();

private:
	double eps;
	double **Array;                           //矩阵
	double *X;                                //结果
	int row;								  //数组的行，column = row + 1
};


#endif