#include <bits/stdc++.h>  
using namespace std;  
void sortedMerge(int a[], int b[], int res[],  
    int n, int m) 
  
{  
    sort(a, a + n); 
    sort(b, b + m); // sort the array b   
  
  
    int i = 0, j = 0, k = 0;  
    while (i < n && j < m) { 
        if (a[i] <= b[j]) {
            res[k] = a[i]; 
            i += 1;  
            k += 1;  
        } else {  
            res[k] = b[j]; 
            j += 1;  
            k += 1;  
        }  
    }  
    while (i < n) { 
        res[k] = a[i];  
        i += 1;  
        k += 1;  
    }  
    while (j < m) { 
        res[k] = b[j];  
        j += 1;  
        k += 1;  
    }  
}  
  
int main()  
{  
    int a[] = { 10, 5, 15, 22, 100 };  
    int b[] = { 20, 3, 2, 12, 1, 7 };  
    int n = sizeof(a) / sizeof(a[0]); 
    int m = sizeof(b) / sizeof(b[0]); 
  
    int res[n + m]; 
    sortedMerge(a, b, res, n, m); 
  
    cout << "The sorted array is: ";  
    for (int i = 0; i < n + m; i++)  
        cout << " " << res[i];  
    cout << "\n";  
  
    return 0;  
}  
