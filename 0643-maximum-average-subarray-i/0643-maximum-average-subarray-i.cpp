class Solution {
public:
    double findMaxAverage(vector<int>& nums,int k ) {
        int currentsum = 0;
        int i;
        
        for(i = 0; i<k; i++){
            currentsum += nums[i];
        }

        int maxsum = currentsum;

        for(int i = k; i< nums.size() ; i++){
            currentsum += nums[i];
            currentsum -= nums[i-k];
            maxsum = max(maxsum , currentsum);
        }

        return (double)maxsum /k;
    }

};