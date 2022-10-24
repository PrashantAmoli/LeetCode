class Solution {
public:
    int ans = 0;
  
    void solve(int i, string &s, vector<string>& arr, vector<int>& used){
      if(i == arr.size()) 
        return;
      
      bool unique = true;
      int size = arr[i].size();
      
      // Take 
      if(size + s.size() <= 26){
        for(auto &c: arr[i]){
          used[c-'a']++;
          s += c;
          if(used[c-'a'] > 1) unique = false;
        }
        
        if(unique){ // if unique 
          int len = s.size();
          ans = max(ans, len);
          solve(i+1, s, arr, used);
        }
        
        while(size--){ // pop arr[i].size() elements from s
          used[s.back()-'a']--;
          s.pop_back();
        }
      }
      
      // Leave
      solve(i+1, s, arr, used);
    }
  
    int maxLength(vector<string>& arr) {
      vector<int> used(26, 0);
      string s = "";
      solve(0, s, arr, used);
      return ans;
    }
};