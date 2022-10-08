#include <iostream>
using namespace std;
void power_set(char a[],int n){
    int j=0;
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            if(i&(1<<j)){
            
                cout<<"{"<<a[j]<<"}";
            }
        }
        if(i==0&&j==0||i==8&&j==0){continue;}
        else {
        cout<<",";
        }

    }
// return 0;
}
int main(){
    int n{3};
    char a[3]{'a','b','c'};
    //cin>>n;
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    cout<<"{";
    //cout<<"{}";
 power_set(a ,n);
 cout<<"}";
    // for(int i=0;i<n;i++){
    //     cout<<a[i];
    // }
    return 0;
}
