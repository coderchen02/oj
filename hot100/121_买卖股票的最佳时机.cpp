// 2026.1.23 20点08分
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;  //记录历史最低价格
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};

