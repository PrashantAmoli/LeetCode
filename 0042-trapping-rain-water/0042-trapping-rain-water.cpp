class Solution {
public:
  // Time: O(2N)  |  Space: O(2N)
  int findGreater(int n, vector<int> &height){
    vector<int> left(n, -1), right(n, -1);
    int maxEle = height[0];
    
    for(int i=0 ; i<n ; i++){
      if( maxEle < height[i] ) 
        maxEle = height[i];
      else if( maxEle > height[i] ) 
        left[i] = maxEle;
    }
    
    maxEle = height[n-1];    
    int ans = 0;
    
    for(int i=n-1 ; i>=0 ; i--){
      if( maxEle < height[i] ) 
        maxEle = height[i];
      else if( maxEle > height[i] ) 
        right[i] = maxEle;
      
      if( left[i]!=-1 && right[i]!=-1 )
        ans += min(left[i], right[i]) - height[i];
    }
    // for(int i=0 ; i<n ; i++)
    //   cout << left[i] << "  :  " << height[i] << "  :  " << right[i] << endl;
    return ans;
  }
  
  // Time: O(N)  |  Space: O(1)
  int optimal(int n, vector<int> &height){
    int l=0, r=n-1, lmax=0, rmax=0, ans=0;
    
    while( l<r ){
      if( height[l] <= height[r] ){
        if(height[l] >= lmax) 
          lmax = height[l];
        else
          ans += lmax -height[l];
        l++;
      }
      else{
        if(height[r] >= rmax) 
          rmax = height[r];
        else
          ans += rmax -height[r];
        r--;
      }
    }
    return ans;
  }
  
  int trap(vector<int>& height) {
    int n = height.size(), ans = 0;
    
    // if( n>2 ) ans = findGreater(n, height);
    if( n>2 ) ans = optimal(n, height);
    
    return ans;
  }
};