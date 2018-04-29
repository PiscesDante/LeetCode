class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy_price = prices[0];
        int sell_price = prices[0];
        int total_profit = 0;
        for (int current_price : prices) {
            if (current_price < buy_price) buy_price = current_price;
            if (current_price > buy_price) {
                total_profit += (current_price - buy_price);
                buy_price = current_price;
            }
        }
        return total_profit;
    }
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录