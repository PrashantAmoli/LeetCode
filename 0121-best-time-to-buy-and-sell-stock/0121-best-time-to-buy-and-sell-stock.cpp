class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy = prices[0], n = prices.size(), maxProfit = 0;
    for(int i=1 ; i<n ; i++){
      int profit = prices[i] - buy;
      maxProfit = max(profit, maxProfit);
      buy = min(buy, prices[i]);
    }
    return maxProfit;
  }
};