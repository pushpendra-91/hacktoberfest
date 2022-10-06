#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(n==1)
        cout<<"one"<<endl;
    else if(n==2)
        cout<<"two"<<endl;
    else if(n==3)
        cout<<"three"<<endl;
    else if(n==4)
        cout<<"four"<<endl;
    else if(n==5)
        cout<<"five"<<endl;
    else if(n==6)
        cout<<"six"<<endl;
    else if(n==7)
        cout<<"seven"<<endl;
    else if(n==8)
        cout<<"eight"<<endl;
    else if(n==9)
        cout<<"nine"<<endl;
    else if(n==0)
        cout<<"zero"<<endl;
    else if(n>9)
        cout<<"Greater than 9"<<endl;
    
    return 0;
}
