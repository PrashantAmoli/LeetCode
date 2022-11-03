class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> map;
        for(int i=0;i<n;i++) map[words[i]]++;  // count the frequency of each word in the array
        int pair=0,same=0;
      
        for(int i=0;i<n;i++){
            string t=words[i];
            string test=t;
            reverse(test.begin(),test.end());
            if(t[0]==t[1]){ // checking for both letters of the word to be same
                pair+=map[t]/2;  // storing the no. of pairs that can be made with that word
                map[t]=map[t]%2;  // updating the no of words that remain unused
                if(map[t]==1)
                    same=2;
            }
            else if(map.count(test)>0){
                pair+=min(map[t],map[test]);
                map[t]=0;
                map[test]=0;
            }   
        }
        return pair*4+same;
    }
};