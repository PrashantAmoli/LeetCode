class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> ans;
      unordered_map<int, int> hash;
      priority_queue<pair<int, int>> pq;
      
      for(auto i: nums) hash[i]++;
      
      for(auto &pair: hash){
        pq.push({-pair.second, pair.first});
        if(pq.size() > k) pq.pop();
      }
      
      while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
      }
      
      return ans;
    }
};