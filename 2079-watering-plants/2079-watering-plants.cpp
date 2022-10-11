class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
      int i=0, n=plants.size(), water=capacity, steps=0;
      
      for(int i=0 ; i<n ; i++){
        if(water < plants[i]){
          water = capacity;
          steps += 2*i;
        }
        water -= plants[i];
        steps++; 
      }
      return steps;
    }
};