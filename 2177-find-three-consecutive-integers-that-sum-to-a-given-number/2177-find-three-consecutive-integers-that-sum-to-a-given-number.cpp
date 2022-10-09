class Solution {
public:
    vector<long long> sumOfThree(long long num) {
      double n1 = (double)(num-3)/3;
      if(n1 == (long long)n1){
        long long n = (long long) n1;
        return { n, n+1 , n+2 };
      }
      return {};
    }
};