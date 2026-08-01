//  METHOD :-1
//   Time Complexity :- O(N^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum=INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                if((nums[i]-1)*(nums[j]-1) > maximum){
                    maximum=(nums[i]-1)*(nums[j]-1);
                }
            }
        }
        return maximum;
    }
};



//  METHOD :-2
// TIME COMPLEXITY : O(N^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n=nums.size();
        return (nums[n-1]-1) * (nums[n-2]-1);
    }
};



//  METHOD :-3
//   TIME COMPLEXITY :- O(N) , But it need Two traversal

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maximum = nums[0];
        int k = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] > maximum) {
                maximum = nums[i];
                k = i;
            }
        }

        int secondMax = -1;

        for(int i = 0; i < n; i++) {
            if(i != k) {
                secondMax = max(secondMax, nums[i]);
            }
        }

        return (maximum - 1) * (secondMax - 1);
    }
};





//  METHOD :-4
//  TIME COMPLEXITY :- O(N) , And also only one Traversal
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=0;
        int second=0;
        for(int x : nums){
            if(x > first){
                second = first;
                first = x ;
            }
            else if(x > second){
                second=x;
            }
        }
        return (first-1) * (second-1);
    }
};