class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windSum=0;
        for(int i=0 ; i<k ; i++){
            windSum+=nums[i];
        }

        int maxSum=windSum;

        for(int i=0 ; i<nums.size()-k ; i++){
            windSum=windSum - nums[i] + nums[k+i];
            maxSum=max(maxSum , windSum);
        }
        return (double)maxSum / k;;
    }
};