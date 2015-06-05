#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int n = 0;
double *X;
double *Y;
double **f;

bool inputXY();
double calculate_f(int start, int end);
bool output_f();
double N(double x);

bool inputXY(){
	cout<<"请输入插值个数：";
	cin>>n;

	X = new double[n];
	Y = new double[n];
	f = new double* [n];
	for (int i = 0; i < n; i++)
		f[i] = new double[n];

	cout<<endl<<"请输入插值表："<<endl;
	for (int i = 0; i < n; i++)
		cin>>X[i];
	for (int i = 0; i < n; i++)
		cin>>Y[i];
	
	return true;
}

bool calculate_f(){
	for (int i = 0; i < n; i++){
		f[i][0] = Y[i];
	}

	for (int i = 0; i < n - 1; i++)
		f[i][1] = ( Y[i + 1] - Y[i] ) / ( X[i + 1] - X[i]);

	for (int j = 2; j < n; j++)
		for (int i = 0; i <  n - j; i++)
			f[i][j] =  ( f[i + 1][j - 1] - f[i][j - 1] ) / (X[i + j] - X[i]);
	
	return true;
}

bool output_f(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i; j++)
			cout<<setw(8)<<f[i][j]<<'\t';
		cout<<endl;
	}

	return true;
}

double N(double x){
	double *P = new double[n];

	for (int i = 0; i < n; i++){
		double C = 1;
		for (int j = 0; j < i; j++)
			C *= x - X[j];
		P[i] = f[0][i] * C;
	}

	double res = 0;
	for (int i = 0; i < n; i++)
		res += P[i];

	delete []P;

	return res;
}

int main(){
	double x;
	inputXY();
	cout<<endl<<"X=";
	cin>>x;
	calculate_f();
	cout<<endl<<"均差表为："<<endl;
	output_f();
	cout<<endl<<"计算结果为：Y="<<N(x)<<endl;


	delete []X;
	delete []Y;
	for (int i = 0; i < n; i++)
		delete []f[i];
	delete []f;

	

	system("pause");
	return 1;
}


