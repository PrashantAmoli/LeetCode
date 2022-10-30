class Solution {
public:
    int countValidWords(string sentence) {
      stringstream ss(sentence); // Break the string into words
      string word;
      int wordCount=0;

      while(ss >> word){
        bool flag = true;
        int hypcount = 0;
        for(int i=0; i<word.size(); i++){

        //If character is a digit
          if(word[i] >= '0' && word[i] <= '9') {
            flag = false;
            break;
          }

        //If character is hyphen
          else if(word[i] == '-') {
            ++hypcount;
            if(word.size()<= 1 || hypcount > 1 || i==0 || i==word.size()-1 || (i<word.size()-1 && !(word[i+1]>='a' && word[i+1] <= 'z'))) {
              flag = false;
              break;
            }
          }
        //If character is a punctuation
          else if((word[i] == ',' || word[i] == '!' || word[i]== '.') && (i!=word.size()-1)){
              flag=false;
              break;
          }
        }
        if(flag) wordCount++;

      }
      return wordCount;
    }
};