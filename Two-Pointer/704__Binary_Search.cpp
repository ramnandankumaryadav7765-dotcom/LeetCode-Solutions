//   Method:-1 , (TC:O(n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};




//   Method:-2 (TC: O(lign)   ,  and instruction is given in question "You must write an algorithm with O(log n) runtime complexity.")
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right = static_cast<int>(nums.size()) - 1; //int right = static_cast<int>(nums.size()) - 1;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return -1;
    }
};