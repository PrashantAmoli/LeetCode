class Solution {
public:
    int maxArea(vector<int>& height) {
      int s=0, e=height.size()-1, ans=0;
      int l=0, r=e;
      
      while(s<e){
        if(height[l] <= height[s] or height[r] <= height[e]){
          l = height[l] < height[s] ? s : l;
          r = height[r] < height[e] ? e : r;
          int area = min(height[l], height[r]) * (e-s);
          ans = max(ans, area);
        }
        
        if(height[s] == height[e]){
          s++;
          e--;
        }
        else if(height[s] < height[e])
          s++;
        else 
          e--;
      }
      return ans;
    }
};