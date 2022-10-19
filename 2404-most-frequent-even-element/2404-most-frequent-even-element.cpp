class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
      unordered_map<int, int> hash;
      priority_queue<pair<int, int>> pq;
      
      for(auto i: nums) 
        if(i % 2 == 0)
          hash[i]++;
      
      for(auto &pair: hash)
        pq.push({pair.second, pair.first});
      
      if(pq.empty()) return -1;
      
      auto ans = pq.top();
      pq.pop();
      
      while(!pq.empty()){
        if(pq.top().first == ans.first)
          ans = pq.top();
        else break;
        pq.pop();
      }
      return ans.second;
    }
};