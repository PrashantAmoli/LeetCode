class Solution {
public:
    string generate(string s) {
        string x = "";
        int n = s.length();
        int count = 1;
        for(int i=0 ; i<n-1 ; i++) {
            if(s[i+1]==s[i] ) count++;
            else{
                x.push_back('0'+count);
                x.push_back(s[i]);
                count=1;
            }
        }
        x.push_back(('0'+count));
        x.push_back(s[n-1]);
        return x;
    }
    
    string countAndSay(int n) {
        if(n==1) return "1";
        return generate(countAndSay(n-1));
    }
};