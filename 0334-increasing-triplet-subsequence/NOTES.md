```
bool increasingTriplet(vector<int>& nums) {
int n = nums.size();
if(n < 3) return false;
int x=INT_MAX, y=INT_MAX;
​
for(int i=0; i<n; i++){
if(nums[i] <= x) x = nums[i];
else if(nums[i] <= y) y = nums[i];
else return true;
}
return false;
}
```
Runtime: 175 ms, faster than 16.15% of C++ online submissions for Increasing Triplet Subsequence.
Memory Usage: 61.6 MB, less than 24.04% of C++ online submissions for Increasing Triplet Subsequence.