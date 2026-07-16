//   Method-1 : By linear search(TC:- O(n))
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>=target){
                return i;
            }
        }
        return nums.size();
    }
};


//    Method-2   Binary search ::: Note:- this is given in question "You must write an algorithm with O(log n) runtime complexity."
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};



/*

Note :- Whenever you write binary search, remember this template:

while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
        return mid;

    else if (nums[mid] < target)
        left = mid + 1;

    else
        right = mid - 1;
}

return left;

*/