#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i,l;
    string c;
    getline(cin>>ws,c);
    l=c.length();   
    for(i=0;i<l;i++)
    {
        if(c[i]==' ')
            cout<<endl;
        else
            cout<<c[i];
    }
    return 0;
}