class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      int n = words.size();
      vector<string> ans;
      map<string, int> hash;
      priority_queue<pair<int, string>> pq;
      
      for(auto &word: words)
        hash[word]++;
      
      // Min Heap
      for(auto &s: hash){
        pq.push({-s.second, s.first});
        if(pq.size() > k) pq.pop();
      }
      
      while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
      }
      reverse(ans.begin(), ans.end());
      
      // Max Heap
//       while(k){
//         set<string> st;
//         int freq = pq.top().first;
        
//         do{
//           st.insert(pq.top().second);
//           pq.pop();
//         } while(k and freq == pq.top().first);
        
//         for(auto &s: st)
//           if(k){
//             ans.push_back(s);
//             k--;
//           }
//       }
      
      return ans;
    }
};