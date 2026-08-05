//    METHOD-1 (Time Complexity:- O(N^2))
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result; 
        int n = nums.size();
        
        // Prevent integer underflow if array has fewer than 4 elements
        if (n < 4) return result; 

        // Sort the array so we can easily skip duplicate combinations
        sort(nums.begin(), nums.end());

        // Loop 1: First number
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

            // Loop 2: Second number
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates

                // Loop 3: Third number
                for (int k = j + 1; k < n - 1; k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue; // Skip duplicates

                    // Loop 4: Fourth number (Fixed starting index to k + 1)
                    for (int l = k + 1; l < n; l++) {
                        if (l > k + 1 && nums[l] == nums[l - 1]) continue; // Skip duplicates

                        // Prevent integer overflow with long long
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                        if (sum == target) {
                            // Then push into the 2D vector(result)
                            result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }
        return result;
    }
};






//  METHOD-2

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // Sort the array to easily skip duplicates and use two pointers
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Two-pointer approach for the remaining two numbers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to prevent integer overflow during addition
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } 
                    else if (sum < target) {
                        left++; // Need a larger sum
                    } 
                    else {
                        right--; // Need a smaller sum
                    }
                }
            }
        }
        return result;
    }
};
