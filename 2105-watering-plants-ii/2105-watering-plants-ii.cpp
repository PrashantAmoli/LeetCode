class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
      // Quality Code 
      int i = 0, j = plants.size() - 1, canA = capacityA, canB = capacityB, res = 0;
      while (i < j) {
        res += (canA < plants[i]) + (canB < plants[j]);
        canA = canA < plants[i] ? capacityA : canA;
        canB = canB < plants[j] ? capacityB : canB;
        canA -= plants[i++];
        canB -= plants[j--];
      }
      return res + (i == j && max(canA, canB) < plants[i]);
      
      // Method 2
//       int n = plants.size();
//       int a=0, b=n-1, waterA=capacityA, waterB=capacityB, refills=0;
      
//       while(a<=b){
//         if(a == b){ // On same plant
//           if(waterA >= waterB){
//             // Alice
//             if(waterA < plants[a]){
//               waterA = capacityA;
//               refills++;
//             }
//             waterA -= plants[a];
//           }
//           else{ 
//             // Bob
//             if(waterB < plants[b]){
//               waterB = capacityB;
//               refills++;
//             }
//             waterB -= plants[b];
//           }
//           break;
//         }
        
//         // Alice
//         if(waterA < plants[a]){
//           waterA = capacityA;
//           refills++;
//         }
//         waterA -= plants[a];
        
//         // Bob
//         if(waterB < plants[b]){
//           waterB = capacityB;
//           refills++;
//         }
//         waterB -= plants[b];
        
//         a++;
//         b--;
//       }
//       return refills;
    }
};