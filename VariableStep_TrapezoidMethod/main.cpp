#include<iostream>
#include<math.h>

using namespace std;

double f(double x);

int main(){

	double a,b,eps,h;
	double T_2n, T_n;            
	cout<<"�������Ͻ���½磺";
	cin>>a>>b;
	cout<<"��������";
	cin>>eps;

	T_n = (b - a)/2 * (f(a) + f(b));                         //�ȼ���h=b-aʱ��T1

	int n = 2;                                               //���������
	while(1){                 

		h = (b - a) / n;                                     //���㲽��

		double S = 0;
		for (double x = a + h; x < b;){
			S += 2 * f(x);
			x += 2 * h;
		}

		T_2n = T_n / 2 + S * h / 2;                         

		double e = fabs((T_2n - T_n));
		if(e > eps)                                         //�������������ʱ������ִ��ѭ��
			T_n = T_2n;
		else
			break;
		

		n *= 2; 
	}

	cout<<"���ֽ���ֵ��"<<T_2n<<endl<<endl;

	system("pause");
	return 0;
}

double f(double x){
	if(!x)
		return 1.0;
	return sin(x)/x;
}