class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minimum = prices[0];
        int maximumProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            minimum = min(minimum, prices[i]);

            int currentProfit = prices[i] - minimum;

            maximumProfit = max(maximumProfit, currentProfit);
        }

        return maximumProfit;
    }
};