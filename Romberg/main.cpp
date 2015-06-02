#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>

using namespace std;

double f(double x);

int main(){

	double a, b, eps;
	cout<<"请输入上界和下界：";
	cin>>a>>b;
	cout<<"请输入误差限：";
	cin>>eps;

	vector<double> T[7];

	double t = 0.0;
	t = (b - a)/2 * (f(a) + f(b));
	T[0].push_back(t);

	double step = 2;                                     //求T0时的子区间个数
	for (int j = 1; j < 7; j++){
		double h = (b - a)/step;                      //步长
		double S = 0.0;
		for (double x = a + h; x < b;){
			S += 2 * f(x);
			x += 2 * h;
		}
		t = t / 2 + h / 2 * S;
		step *= 2;

		T[j].push_back(t);
	}


	int k = 0;
	for (k = 1; k < 7; k++){
		for (int i = 1; i <= k; i++){
			t = ((pow(4, i) * T[k][i - 1]) - T[k - 1][i - 1]) / (pow(4, i) - 1);
			T[k].push_back(t);
		}
	}

	int m;
	for (m = 1; m < 7; m++){
		double e = fabs(T[m].back() - T[m - 1].back());
		if(e < eps)
			break;
	}

	cout<<endl<<"T-数表如下："<<endl;
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= i; j++){
			cout << setprecision(8);
			cout<<setw(9)<<T[i][j]<<"   ";
		}
		cout<<endl;
	}

	cout << setprecision(8);
	cout<<endl<<"积分近似值为："<<T[m][m]<<endl<<endl;

	system("pause");
	return 0;
}

double f(double x){
	if(!x)
		return 1.0;
	else
		return sin(x)/x;
}