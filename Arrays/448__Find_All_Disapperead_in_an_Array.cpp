// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {

//         sort(nums.begin(), nums.end());

//         vector<int> ans;
//         int expected = 1;

//         for (int i = 0; i < nums.size(); i++) {

//             while (expected < nums[i]) {
//                 ans.push_back(expected);
//                 expected++;
//             }

//             if (expected == nums[i]) {
//                 expected++;
//             }
//         }

//         while (expected <= nums.size()) {
//             ans.push_back(expected);
//             expected++;
//         }

//         return ans;
//     }
// };




class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0 ; i<nums.size() ; i++){
            st.insert(nums[i]);
        }

        vector<int>ans;
        for(int i=1 ; i<=nums.size() ; i++){ // hete we use "i<=nums.size()" because question say 1 to n , and n is size of the nums. if we only take "i<nums.size()" then it leave one element.
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};