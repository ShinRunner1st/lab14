#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[])
{
    double sum = 0.0, sum2 = 0.0, sum3 = 1.0, sum4 = 0.0;
    double num = n;
    double tempmin = a[0], tempmax = a[0];
    for (int i = 0; i < n; i++) sum += a[i];
    b[0] = sum/num;
    for (int i = 0; i < n; i++) sum2 += pow(a[i] - b[0],2);
    b[1] = sqrt(sum2/num);
    for (int i = 0; i < n; i++) sum3 *= a[i];
    b[2] = pow(sum3,(1/num));
    for (int i = 0; i < n; i++) sum4 += 1/a[i];
    b[3] = num/sum4;
    for (int i = 0; i < n; i++) if(tempmin < a[i]) tempmin = a[i];
    for (int i = 0; i < n; i++) if(tempmax > a[i]) tempmax = a[i];
    b[4] = tempmin;
    b[5] = tempmax;
}