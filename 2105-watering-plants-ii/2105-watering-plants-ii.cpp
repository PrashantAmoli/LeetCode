class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
      int n = plants.size();
      int a=0, b=n-1, waterA=capacityA, waterB=capacityB, refills=0;
      
      while(a<=b){
        if(a == b){ // On same plant
          if(waterA >= waterB){
            // Alice
            if(waterA < plants[a]){
              waterA = capacityA;
              refills++;
            }
            waterA -= plants[a];
          }
          else{ 
            // Bob
            if(waterB < plants[b]){
              waterB = capacityB;
              refills++;
            }
            waterB -= plants[b];
          }
          break;
        }
        
        // Alice
        if(waterA < plants[a]){
          waterA = capacityA;
          refills++;
        }
        waterA -= plants[a];
        
        // Bob
        if(waterB < plants[b]){
          waterB = capacityB;
          refills++;
        }
        waterB -= plants[b];
        
        a++;
        b--;
      }
      return refills;
    }
};