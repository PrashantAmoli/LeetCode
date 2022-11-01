class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
      unordered_map<string, string> hash;
      
      for(int i=0; i<knowledge.size(); i++)
        hash[knowledge[i][0]] = knowledge[i][1];
      
      string ans;
      int i = 0, n = s.size();
      
      while(i < n){
        if(s[i] == '('){
          i++;
          string key;
          while(i<n and s[i] != ')')
            key += s[i++];
          ans += (hash.find(key) == hash.end()) ? "?" : hash[key];
        }
        else
          ans += s[i];
        i++;
      }
      return ans;
    }
};