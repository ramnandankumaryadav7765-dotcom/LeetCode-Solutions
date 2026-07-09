//  METHOD:- 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>ans;
        for(int x : nums){
            if(ans.find(x) != ans.end()){
                return true;
            }
            ans.insert(x);
        }
        return false;
    }
};


//  Method:- 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>ans;
        for(int x : nums){
            ans.insert(x);
        }
        if(nums.size() != ans.size()){
            return true;
        }
        return false;
    }
};


// METHOD:- 3

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
