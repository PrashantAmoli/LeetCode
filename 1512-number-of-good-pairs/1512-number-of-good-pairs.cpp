class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
      int ans=0;
      unordered_map<int, int> hash;
      for(int i=0 ; i<nums.size() ; i++)
        ans += hash[nums[i]]++;
      return ans;
    }
};