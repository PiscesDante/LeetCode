class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int len = prices.size();
        int buy_price = prices[0];
        int sell_price = prices[0];
        int max_profit = 0;
        for (int i = 0; i < len; ++i) {
            if (prices[i] < buy_price) {
                buy_price = prices[i];
                sell_price = prices[i];
            }
            if (prices[i] > sell_price) {
                sell_price = prices[i];
                if (sell_price - buy_price > max_profit) max_profit = sell_price - buy_price;
            }
        }
        return max_profit;
    }
};

// 执行用时：8 ms
// 已经战胜 69.22 % 的 cpp 提交记录