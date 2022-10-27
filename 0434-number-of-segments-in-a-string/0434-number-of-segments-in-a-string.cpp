class Solution {
public:
    int countSegments(string s) {
      string segment;
      stringstream ss(s);
      int count = 0;
      while(ss >> segment) count++;
      return count;
    }
};