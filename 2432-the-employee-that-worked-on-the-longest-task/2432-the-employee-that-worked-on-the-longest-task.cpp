class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
      int ans = logs[0][0], time = logs[0][1];
      for(int i=1; i<logs.size(); i++){
        if(logs[i][1] - logs[i-1][1] >= time){
          ans = (time == logs[i][1] - logs[i-1][1]) ? min(ans, logs[i][0]) : logs[i][0];
          time = logs[i][1] - logs[i-1][1];
        }
      }
      return ans;
    }
};