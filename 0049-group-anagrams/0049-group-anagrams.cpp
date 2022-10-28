class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      string s = "";
      vector<vector<string>> ans;
      unordered_map<string, vector<string>> hash;
      
      for(int i=0 ;  i<strs.size() ; i++){
        s = strs[i];
        sort(s.begin(), s.end());
        hash[s].push_back(strs[i]);
      }
      
      for(auto &i: hash) ans.push_back(i.second);
      return ans;
    }
};