#include <iostream>
#include <cmath>

int main(){
  int counter = 0;
  int pair = -1;
  int next;
  int prev;
  int prevprev;
  int current;
  bool adjacent = false;
  bool increasing = true;

  for (int i = 156218; i < 652527; i++){
    for (int j = 0; j < 6; j++){
      // std::cout << "CURRENT: " << current << " " << i << std::endl;
      if (j == 0){
        current = (i % (int)pow(10.0, j + 1.0))/(int)pow(10.0, j * 1.0);
        prev = -1;
        prevprev = -1;
      }

      next = (i % (int)pow(10.0, j + 2.0))/(int)pow(10.0, (j+1) * 1.0);

      if (j == 6){
        next = -1;
      }


      if (prev < current && prev != -1){
        increasing = false;
      }
      if (prev == current && current != next && current != prevprev){
         // std::cout << "ADJACENT!!: " << current << " " << prev << " " << prevprev << std::endl;
        adjacent = true;
        // pair = j;
      }
      // if (j == pair + 1 && current == prevprev){
      //   adjacent = false;
      // }

      prevprev = prev;
      prev = current;
      current = next;
    }
    if (adjacent && increasing){
      std::cout << i << std::endl;
      counter++;
    }

    adjacent = false;
    increasing = true;
    pair = -1;
  }
  std::cout << "RESULT: " << counter << std::endl;
}
