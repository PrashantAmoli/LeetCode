class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(), nums.end());
      int ans = 0;
      
      for (int i = 0; i < nums.size(); i++) {
        if (s.find(nums[i] - 1) != s.end()) continue;
        int count = 1;
        while (s.find(nums[i] + count) != s.end()) count++;
        ans = max(ans, count);
      }
      return ans;
    }
};