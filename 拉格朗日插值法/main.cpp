#include<iostream>
#include<math.h>

using namespace std;
 
int n = 0;                                          //插值个数
double *X;                                          //插值表的X
double *Y;                                          //插值表的Y

bool inputXY();                                     //输入XY
double l(int i, double x);                          //计算l0(x),l1(x),l2(x)...
double L(double x);                                 //计算L(x)

int main(){
	inputXY();
	double x;
	cout<<endl<<"请输入需要计算的自变量x：";
	cin>>x;
	cout<<endl<<"计算结果是：Y = "<<L(x)<<endl<<endl;
	
	delete []X;
	delete []Y;
	system("pause");
	return 0;
}

bool inputXY(){
	cout<<"请输入插值个数：";
	cin>>n;

	X = new double[n];
	Y = new double[n];

	cout<<endl<<"请输入差值表："<<endl;
	for (int i = 0; i < n; i++)
		cin>>X[i];
	for (int i = 0; i < n; i++)
		cin>>Y[i];
	
	return true;
}

double l(int i, double x){
	double P1 = 1;
	double P2 = 1;

	for (int k = 0; k < n; k++){
		if(k == i)
			continue;
		P1 *= (x - X[k]);
		P2 *= (X[i] - X[k]);
	}

	return P1 / P2;
}

double L(double x){
	double res = 0;
	for (int i = 0; i < n; i++)
		res +=  Y[i] * l(i, x);

	return res;
}

