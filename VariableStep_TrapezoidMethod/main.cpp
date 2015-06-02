#include<iostream>
#include<math.h>

using namespace std;

double f(double x);

int main(){

	double a,b,eps,h;
	double T_2n, T_n;            
	cout<<"请输入上界和下界：";
	cin>>a>>b;
	cout<<"请输入误差：";
	cin>>eps;

	T_n = (b - a)/2 * (f(a) + f(b));                         //先计算h=b-a时的T1

	int n = 2;                                               //子区间个数
	while(1){                 

		h = (b - a) / n;                                     //计算步长

		double S = 0;
		for (double x = a + h; x < b;){
			S += 2 * f(x);
			x += 2 * h;
		}

		T_2n = T_n / 2 + S * h / 2;                         

		double e = fabs((T_2n - T_n));
		if(e > eps)                                         //当误差大于误差限时，继续执行循环
			T_n = T_2n;
		else
			break;
		

		n *= 2; 
	}

	cout<<"积分近似值："<<T_2n<<endl<<endl;

	system("pause");
	return 0;
}

double f(double x){
	if(!x)
		return 1.0;
	return sin(x)/x;
}