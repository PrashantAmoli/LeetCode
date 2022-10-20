class Solution {
public:
    string intToRoman(int num) {
      string ans = "";
      // map<int,string> hash = {
      //       {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
      //       {10,"X"}, {9,"IX"}, {5,"V"} , {4,"IV"} , {1,"I"}};
      
      // while(num != 0){
      //     auto it = hash.lower_bound(num);
      //     if(it->first != num){
      //         cout << it->first << " ->";
      //         it--; 
      //     }//in lower_bound if value is not present in map it points to next highest element
      //     ans += it->second;
      //     num -= it->first;
      //     cout << it->first << endl;
      // }
      
      
      vector<pair<int,string>> hash = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
            {10,"X"}, {9,"IX"}, {5,"V"} , {4,"IV"} , {1,"I"}};
      
      for (int i=0; i<hash.size(); i++){
        auto node = hash[i];
        int mf = num  / node.first;

        for (int j = 0;j < mf; j++)
            ans += node.second;
        num = num % node.first;
      }
      return ans;
    }
};