#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int k = n-2;
    
        for(int i=n-1 ; i>0 ; i--)
        {
            if(nums[i]<=nums[i-1])
                k--;
            else
                break;
        }
        
        if(k==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
          for(int j=n-1 ; j>0 ; j--){
            if(nums[j]>nums[k]){
                int temp = nums[k];
                nums[k] = nums[j];
                nums[j] = temp;
                break;
            }        
        }
        reverse(nums.begin()+k+1,nums.end());
    }}
};
