#include"Doolittle.h"
#include<iostream>

using namespace std;

int main(){
	cout<<"请输入矩阵维数：";
	int n;
	cin>>n;
	Doolittle d(n, n);
	d.Decomposition();
	d.ShowResult();

	system("pause");
}