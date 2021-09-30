#include<iostream>
using namespace std;

int fib(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n, num=0;
    cout<<"Enter the no. of term you want in fibonaci series: ";
    cin>>n;
    num = fib(n);
    cout<<"Term is: "<<num;
}