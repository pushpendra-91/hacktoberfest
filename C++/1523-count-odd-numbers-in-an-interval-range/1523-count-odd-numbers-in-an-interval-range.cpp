class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0)
            low++;
        if(high%2==0)
            high--;
        int ans=(high-low)/2;
        return ans+1;
    }
};