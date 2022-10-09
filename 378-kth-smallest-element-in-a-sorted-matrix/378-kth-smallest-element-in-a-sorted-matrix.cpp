class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      
      // Method 1
      // int n = matrix.size();
      // vector<int> v;
      // for(int i=0 ; i<n ; i++)
      //   for(int j=0 ; j<n ; j++)
      //     v.push_back(matrix[i][j]);
      // sort(v.begin(), v.end());
      // return v[k-1];
      
      // Method 2: Max Heap
      int m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
      priority_queue<int> maxHeap;
      for (int r = 0; r < m; r++) {
          for (int c = 0; c < n; c++) {
              maxHeap.push(matrix[r][c]);
              if (maxHeap.size() > k) maxHeap.pop();
          }
      }
      return maxHeap.top();
    }
  
};