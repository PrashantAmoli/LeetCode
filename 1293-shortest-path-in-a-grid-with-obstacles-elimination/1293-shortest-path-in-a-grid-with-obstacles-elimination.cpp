class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
      int m=grid.size(), n=grid[0].size(), ans = 1e9;
      int x, y, s, o;
      vector<vector<int>> vis(m, vector<int>(n, -1));
      
      queue<vector<int>> q;
      q.push({0, 0, 0, k});
      
      while(!q.empty()){
        auto front=q.front();
        q.pop();
        x = front[0];
        y = front[1];

        // Exit if current position is outside of the grid
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
          continue;
        
        // Destination found
        if(x==grid.size()-1 && y==grid[0].size()-1)
          return front[2];

        if(grid[x][y] == 1){
          if(front[3] > 0)
            front[3]--;
          else
            continue;
        }

        if(vis[x][y] != -1 && vis[x][y] >= front[3])
          continue;
        
        vis[x][y] = front[3];

        q.push({x+1, y, front[2]+1, front[3]});
        q.push({x, y+1, front[2]+1, front[3]});
        q.push({x-1, y, front[2]+1, front[3]});
        q.push({x, y-1, front[2]+1, front[3]});
      }
      return -1;
    }
};