class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

        int zeroCount = 0;

        for (int num : nums) {
            if (num == 0)
                zeroCount++;
        }

        int zerosAtEnd = 0;

        // It is used to check , ki pahle se hi last me kitna Zeroes already hai , like agar total 10 size ke array me 4 zeroes hai to last ke 4 positions par zero hi hogi and agar pahle se kuchh 1 ya 2 ya 3 ya ho sakta hai 4 means ki agar pahle se hi kuchh zeros avaliable hai us last ke 4 positions par to hame usse kam swap ("totalNumberOfZeroes - zerosAtEnd") karna parega na.
        for (int i = nums.size() - zeroCount; i < nums.size(); i++) {
            if (nums[i] == 0)
                zerosAtEnd++;
        }

        return zeroCount - zerosAtEnd;
    }
};