class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
      int ans=0;
      for(auto s: sentences){
        string word;
        int count = 0;
        stringstream ss(s);
        while(ss >> word) count++;
        ans = max(ans, count);
      }
      return ans;
    }
};