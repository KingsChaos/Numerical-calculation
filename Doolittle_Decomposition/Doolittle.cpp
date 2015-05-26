#include"Doolittle.h"

using namespace std;


Doolittle::Doolittle(int row, int col):Matrix(row, col,false), L(row, col), U(row, col){}

bool Doolittle::Decomposition(){
	if(Matrix.getrow() != Matrix.getcolumn() )
		return false;
	int n = Matrix.getrow();

	for (int i = 0; i < n; i++)                                   
		L.array[i][i] = 1;										  //Lnn = 1

	for (int i = 0; i < n; i++)
		U.array[0][i] = Matrix.array[0][i];                       //U1i = A1i

	for (int i = 0; i < n; i++)
		L.array[i][0] = Matrix.array[i][0] / U.array[0][0];       //Li1 = Ai1 / U11

	for (int i = 1; i < n; i++){                                  //先求U的第i行，再求L的第i列

		for (int j = i; j < n; j++){                              //求U的第i行，第j列元素
			double product = 0;
			for (int k = 0; k <= i - 1; k++)
				product += U.array[k][j] * L.array[i][k];
			U.array[i][j] = Matrix.array[i][j] - product;
		}

		for (int j = i; j < n; j++){                              //求L的第i列，第j行元素

			if(U.array[i][i] == 0)                                //如果Uii = 0 出错
				return false; 

			double product = 0;
			for (int k = 0; k <= i - 1; k++)
				product += L.array[j][k] * U.array[k][i];
			L.array[j][i] = ( Matrix.array[j][i] - product ) / U.array[i][i];
		}
	}

	return true;
}

bool Doolittle::Calculation(){
	
}

bool Doolittle::ShowResult(){
	cout<<"原";
	Matrix.Show();
	cout<<endl<<"分解结果："<<endl<<endl;
	cout<<"下三角L";
	L.Show();
	cout<<endl<<"上三角U";
	U.Show();

	return true;
}

