//   Method:-1  (Time Complexity:- O(n) , Space Complexity:- O(n) . It required an extra space).

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int index = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[index] = nums[left] * nums[left];
                left++;
            } else {
                ans[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }

        return ans;
    }
};


//   Method:-2  (Time Complexity:- O(n logn) , Space Complexity:- O(1) . This happen in-place it doesn't required any extra spaces).

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            nums[i]*=nums[i];
        }
        sort(nums.begin() , nums.end());
        return nums;
    }
};