class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      string s1 = "";
      for(auto &str: word1) s1 += str;
      
      string s2 = "";
      for(auto &str: word2) s2 += str;
      
      int n1 = s1.size();
      if(n1 != s2.size()) return false;
      
      for(int i=0; i<n1; i++)
        if(s1[i] != s2[i])
          return false;
      return true;
    }
};