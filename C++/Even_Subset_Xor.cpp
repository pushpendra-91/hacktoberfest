/*
Problem
A number XX is called bad if its binary representation contains odd number of 11 bits. For example, X = 13 = (1101)_2X=13=(1101) 
2
​
  is bad while X = 3 = (11)_2X=3=(11) 
2
​
  is not bad.

Chef calls an array AA of length NN special if the following conditions hold:

For each 1 \le i \le N1≤i≤N, 0 \le A_i \lt 2^{20}0≤A 
i
​
 <2 
20
 
All the elements of AA are distinct
There does not exist any non-empty subset of AA such that the bitwise XOR of the subset is bad.
For example,

A = [2, 3, 4]A=[2,3,4] is not special because the XOR of the subset [2, 3][2,3] is 2 \oplus 3 = 12⊕3=1, which is bad. (\oplus⊕ denotes the bitwise XOR operation)
A = [3, 3]A=[3,3] is not special because its elements are not distinct.
A = [3, 5]A=[3,5] is special because it satisfies all the conditions.
Chef challenges you to construct any special array of length NN. Can you complete Chef's challenge?

Input Format
The first line of input contains a single integer TT, denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains a single integer NN — the length of the special array to be constructed.
Output Format
For each test case, output a single line containing NN space-separated integers, denoting the elements of the special array of length NN you constructed.

Note: It can be proved that a special array of length NN always exists under the given constraints.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq N \leq 10001≤N≤1000
0 \leq A_i \lt 2^{20}0≤A 
i
​
 <2 
20
*/
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int count=1;
        cout<<0<<" ";
       
           for(int j=3;;j++)
           {
               int i=j;
            
               if(count!=n)
               {
                    int c=0;
                    do
                    {
                        if(i%2==1)
                        c++;
                        i=i/2;
                        
                    } while (i!=0);

                    if(c%2==0)
                    {
                        cout<<j<<" ";
                        count++;
                    }
               }
               else
               break;
            
               
           }
        
        cout<<"\n";
    }
    
}
