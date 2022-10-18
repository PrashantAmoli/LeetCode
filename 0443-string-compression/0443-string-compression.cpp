class Solution {
public:
    int compress(vector<char>& ch) {
      int n = ch.size();
      int index = 0;
      int i = 0;
      
      while(i < n){
          int j = i;
          while(j < n && ch[i] == ch[j]) j++;
          ch[index++] = ch[i];
        
          if(j - i > 1){
              string count = to_string(j-i);
              for(int c = 0; c < count.length();c++){
                  ch[index++] = count[c];
              }
          }
          i = j;
      }
      return index;
    }
};