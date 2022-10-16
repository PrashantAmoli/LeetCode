```
// TABULATION
int difficulty(vector<int> &jobDifficulty, int n, int d){
vector<vector<int>> dp(n + 1, vector<int> (d + 1, 1e9));
dp[0][0] = 0;
​
for(int i = 1; i <= n; i++){
for(int j = 1; j <= d; j++){
int maxi = INT_MIN;
for(int k = i - 1; k >= j - 1; k--){
maxi = max(maxi, jobDifficulty[k]);
dp[i][j] = min(dp[i][j], maxi + dp[k][j - 1]);
}
}
}
return dp[n][d];
}
​
// MEMOIZATION
int difficulty(vector<int> &jobDifficulty, int start, int n, int d, vector<vector<int>> &dp){
if(d == 1){
int maxi = jobDifficulty[start];
for(int i = start + 1; i < n; i++)
maxi = max(maxi, jobDifficulty[i]);
return maxi;
}