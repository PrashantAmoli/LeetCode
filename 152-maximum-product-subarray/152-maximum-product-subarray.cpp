class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int mini=1, maxi=1, ans=INT_MIN;
      
      for(int &i: nums){
        if(i == 0) mini = maxi = 1;
        int MAXI = maxi;
        maxi = max({ i*maxi, i*mini, i });
        mini = min({ i*MAXI, i*mini, i });
        ans = max(ans, maxi);
      }
      return ans;
    }
};