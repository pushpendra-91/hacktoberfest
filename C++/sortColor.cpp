class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1) return;
        int l=0,h=nums.size()-1,m=0,temp;
        while(m<=h){
            if(nums[m] == 0){
                // swap(l,m);
                temp = nums[l];
                nums[l] = nums[m];
                nums[m] = temp;
                l++;
                m++;
            } else if(nums[m] == 2){
                // swap(h,m);
                temp = nums[h];
                nums[h] = nums[m];
                nums[m] = temp;
                h--;
            }else m++;
        }
        
    }
};