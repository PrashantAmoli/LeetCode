class Solution {
public:
    bool wordPattern(string pattern, string s) {
      int n = pattern.size();
      unordered_map<string, char> mp1;
      unordered_map<char, string> mp2;
      
      vector<string> v;
      string word;
      stringstream ss(s);
      while(ss >> word) v.push_back(word);
      
      if(n != v.size()) return false;
      
      for(int i=0 ; i<n ; i++){
        if(mp1.find(v[i]) == mp1.end())
          mp1[v[i]] = pattern[i];
        else if(mp1[v[i]] != pattern[i])
          return false;
        
        if(mp2.find(pattern[i]) == mp2.end())
          mp2[pattern[i]] = v[i];
        else if(mp2[pattern[i]] != v[i])
          return false;
      }
      if(n != pattern.size()) return false;
      return true;
    }
};