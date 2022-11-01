class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& grid){
      if(i>=grid.size())
          return j;
      else if(grid[i][j]==1 && j+1<grid[0].size() && grid[i][j+1]==1)
          return solve(i+1, j+1, grid);
      else if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1)
          return solve(i+1, j-1, grid);
      else
          return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {       
      int row = grid.size();
      int col = grid[0].size();
      vector<int> ans(col);
      for(int i=0; i<col; i++)
          ans[i] = solve(0, i, grid);
      return ans;
    }
};