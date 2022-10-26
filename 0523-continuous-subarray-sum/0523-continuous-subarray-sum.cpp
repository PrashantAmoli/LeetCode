class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      if(n==1) return false;
      if(k==1) return true;   
      
      long long sum = 0;
      unordered_map<int,int> mp;
      mp[0] = -1;
      
      for(int i=0 ; i<n ; i++){
        sum += nums[i];
        int rem = sum % k;

        if(mp.count(rem)){
            if(i-mp[rem] >= 2) 
              return true;
        }
        else mp[rem]=i;
      }
      return false;
    }
};