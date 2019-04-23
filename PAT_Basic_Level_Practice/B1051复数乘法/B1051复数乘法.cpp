#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	const double eps =1e-8;
	double R1, P1, R2, P2;
	cin >> R1 >> P1 >> R2 >> P2;
	double A= R1 * cos(P1)*R2*cos(P2) - R1 * sin(P1)*R2*sin(P2), B = R1 * sin(P1)*R2*cos(P2) + R1 * cos(P1)*R2*sin(P2);
	if(A<-0.01) printf("%.2lf", A);
	else
	{
		printf("%.2lf",fabs(A));
	}
	if (B<-0.01)
	{
		printf("%.2lfi", B);
	}
	else 
	{
		printf("+");
		printf("%.2lfi", fabs(B));
	}
	return 0;
}
