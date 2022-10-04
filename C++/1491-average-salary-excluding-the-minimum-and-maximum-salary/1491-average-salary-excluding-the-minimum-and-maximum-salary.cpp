class Solution {
public:
    double average(vector<int>& salary) {
        int max=salary[0];
        int min=salary[0];
        for(int i=1;i<salary.size();i++){
            if(salary[i]>max){
                max=salary[i];
            }
            if(salary[i]<min){
                min=salary[i];
            }
        }
        double sum=0;
        for(int j=0;j<salary.size();j++){
            sum=sum+salary[j];
        }
        double ans= (sum-max-min)/(salary.size()-2);
        return ans;
    }
};