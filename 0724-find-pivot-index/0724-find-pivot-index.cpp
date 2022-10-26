class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size(), ans=-1;
      vector<int> l(n, 0), r(n, 0); 
      
      r[n-1] = nums[n-1];
      for(int i=n-2 ; i>=0 ; i--)
        r[i] = r[i+1] + nums[i];
      
      l[0] = nums[0];
      
      if(l[0]-nums[0] == r[0]-nums[0]) 
          return 0;
      
      for(int i=1 ; i<n ; i++){
        l[i] = l[i-1] + nums[i];
      
        if(l[i]-nums[i] == r[i]-nums[i]) 
          return i;
      }
      
      return ans; 
    }
};