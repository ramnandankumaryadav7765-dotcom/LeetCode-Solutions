//  METHOD:- -2
//   TIME COMPLEXITY:- O(N^3) , So thats why it gives Time Limit Exceeds(TLE)

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int check_start = min(nums[i], nums[j]);
                int gcd_val = 1;

                for (int k = check_start; k > 0; k--) {
                    if (nums[i] % k == 0 && nums[j] % k == 0) {
                        gcd_val = k; 
                        break;
                    }
                }
                
                // Calculate strength using long long to prevent integer overflow
                long long product = (long long)nums[i] * nums[j];
                long long current_strength = product / ((long long)gcd_val * gcd_val);
                
                ans = max(ans, current_strength);
            }
        }
        return ans;
    }
};



//  METHOD:- 2
// TIME COMPLEXITY:- O(n^2logM)  | Because Each gcd(a,b): O(log(min(a,b)))
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

        long long maximum = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                long long hcf = gcd(nums[i], nums[j]);
                long long strength =(1LL * nums[i] * nums[j]) /(hcf * hcf);
                maximum = max(maximum, strength);
            }
        }

        return maximum;
    }
};
