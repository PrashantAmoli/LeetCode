class Solution {
public:
    int findMaxK(vector<int>& nums) {
      unordered_map<int, bool> hash;
      int ans = -1;
      for(int i=0 ; i<nums.size() ; i++){
        if(hash.find(-nums[i]) != hash.end())
          ans = max(ans, abs(nums[i]));
        hash[nums[i]] = true;
      }
      return ans;
    }
};