class Solution {
public:
    bool checkIfPangram(string sentence) {
      // vector<int> v(26, 0);
      // for(int i=0; i<sentence.size(); i++)
      //   v[sentence[i]-'a'] = 1;
      // return accumulate(v.begin(), v.end(), 0) == 26;
      
      set<int> st;
      for(int i=0; i<sentence.size(); i++)
        st.insert(sentence[i] - 'a');
      return st.size() == 26;
    }
};