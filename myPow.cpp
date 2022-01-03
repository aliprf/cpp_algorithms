#include <iostream>
#include <vector>
#include <string>

using namespace std;

double myPow(double x, int n);
double calcPow(double x, int n);

int main()
{
    cout <<"2.00000^5 => "<< myPow(2.00000, 10) << "\n\r";
    cout <<"2.00000^5 => "<<myPow(2.00000, -1) << "\n\r";
    
}

double myPow(double x, int n) 
{
    return n>0 ? calcPow(x, n): 1/calcPow(x, n);
}

double calcPow(double x, int n)
{
    if (n==0)
        return 1;

    if(n % 2 ==0)
        return calcPow(x,n/2)*calcPow(x,n/2);
    else
        return x*calcPow(x,n/2) * calcPow(x,n/2);
}