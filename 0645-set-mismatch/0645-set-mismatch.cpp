class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      int size=0;
      vector<int> ans(2);
      vector<int> hash(n+1, 0); 
      sort(nums.begin(), nums.end());
      
      for(int i=0 ; i<n ; i++)
        hash[nums[i]]++;
      
      for(int i=1 ; i<=n and size < 2 ; i++){
        if(hash[i] == 0) {
          ans[1] = i;
          size++;
        }
        else if(hash[i] == 2) {
          ans[0] = i;
          size++;
        }
      }
      return ans;
    }
};