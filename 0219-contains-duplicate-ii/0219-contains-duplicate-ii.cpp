class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> hash;
      
      for(int i=0 ; i<nums.size() ; i++){
        if(hash.find(nums[i]) == hash.end()) hash[nums[i]] = i;
        else{
          if(abs(hash[nums[i]] - i) <= k) return true;
          else hash[nums[i]] = i;
        }
      }
      
      // int i=0, j=0, n=nums.size();
      // for(int i=0 ; i<n-1 ; i++)
      //   for(int j=i+1 ; j<n and (j-i)<=k ; j++)
      //     if(nums[i]==nums[j]) 
      //       return true;
      return false;
    }
};