Runtime: 3 ms, faster than 98.05% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
Memory Usage: 8.2 MB, less than 86.03% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
```
int ans = 0;
​
void solve(int i, string &s, vector<string>& arr, vector<int>& used){
if(i == arr.size())
return;
​
bool unique = true;
int size = arr[i].size();
​
// Take
if(size + s.size() <= 26){
for(auto &c: arr[i]){
used[c-'a']++;
s += c;
if(used[c-'a'] > 1) unique = false;
}
​
if(unique){ // if unique
int len = s.size();
ans = max(ans, len);
solve(i+1, s, arr, used);
}
​
while(size--){ // pop arr[i].size() elements from s
used[s.back()-'a']--;
s.pop_back();
}
}
​
// Leave
solve(i+1, s, arr, used);
}
​
void solveFast(int i, string &s, vector<string>& arr, vector<int>& used){
if(i == arr.size())
return;