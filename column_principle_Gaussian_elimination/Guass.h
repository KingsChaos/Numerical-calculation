#ifndef GUASS_H
#define GUASS_H

#include<iostream>

using namespace std;

class Guass{

public:
	Guass();
	~Guass();
	bool SelctMaj(int k);                     //ѡȡ��k������Ԫ
	bool Exchange(int i, int j);              //������i�к͵�j��
	bool Elimination();                       //��Ԫ
	bool Compute();                           //���
	bool Show();                              //��ʾ����
	bool ShowX();                             //��ʾ���
	bool Start();

private:
	double eps;
	double **Array;                           //����
	double *X;                                //���
	int row;								  //������У�column = row + 1
};


#endif