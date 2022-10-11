class Solution {
    vector<int> dp;
public:
    int solve(int n, int target, vector<int> &nums){
      if(target == 0) return 1;
      if(dp[target] != -1) return dp[target];
      
      int ans = 0;
      for(int i=0 ; i<n ; i++)
        if( nums[i] <= target )
          ans += solve(n, target-nums[i], nums);
      return dp[target] = ans;
    }
  
    int combinationSum4(vector<int>& nums, int target) {
      int n = nums.size();
      dp.resize(target+1, -1);
      return solve(n, target, nums);
    }
};