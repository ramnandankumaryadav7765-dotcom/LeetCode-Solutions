//  Method-1(Brute Force , Time Complexity:- O(n^2)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans.insert(nums1[i]);
                }
            }
        }
        // Convert the unordered_set to a vector using its iterators , because the function signature expects a vector<int>
        return vector<int>(ans.begin(), ans.end());
    }
};



// Method-2 (Using unordered_set , Time Complexity:- O(n))

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> ans;

        for (int x : nums2) {

            if (set1.count(x)) {   // This only return true or false(1 or 0), It can use in only set not in vector
                ans.insert(x);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};


//   Method-3   (TC: O(n))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin() , nums2.end());
        unordered_set<int> ans;

        for(int x : set2){
            if(set1.find(x) != set1.end()){
                ans.insert(x);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};