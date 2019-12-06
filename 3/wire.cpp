#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cctype>
#include <vector>


int main(){

  char direction;
  int spaces;
  char next;

  int x = 0;
  int y = 0;
  int distance = 1;

  std::vector< std::vector<int> > wire0;
  std::vector< std::vector<int> > wire1;


  while(std::cin >> direction) {
    std::cin >> spaces;
    if (direction == 'R'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(i + x);
        coord.push_back(y);
        coord.push_back(distance++);
        wire0.push_back(coord);
      }
      x = spaces + x;
    }
    else if (direction == 'L'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(x - i);
        coord.push_back(y);
        coord.push_back(distance++);
        wire0.push_back(coord);
      }
      x = x - spaces;
    }
    else if (direction == 'U'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(x);
        coord.push_back(y + i);
        coord.push_back(distance++);
        wire0.push_back(coord);
      }
      y = y + spaces;
    }
    else if (direction == 'D'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(x);
        coord.push_back(y - i);
        coord.push_back(distance++);
        wire0.push_back(coord);
      }
      y = y - spaces;
    }
    std::cin >> next;
    if (next == ';'){
      break;
    }
    // std::cout << "WIRE0" << std::endl;
  }

  x = 0;
  y = 0;
  distance = 1;

  while(std::cin >> direction) {
    std::cin >> spaces;
    if (direction == 'R'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(i + x);
        coord.push_back(y);
        coord.push_back(distance++);
        wire1.push_back(coord);
      }
      x = spaces + x;
    }
    else if (direction == 'L'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(x - i);
        coord.push_back(y);
        coord.push_back(distance++);
        wire1.push_back(coord);
      }
      x = x - spaces;
    }
    else if (direction == 'U'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(x);
        coord.push_back(y + i);
        coord.push_back(distance++);
        wire1.push_back(coord);
      }
      y = y + spaces;
    }
    else if (direction == 'D'){
      for (int i = 1; i <= spaces; i++){
        std::vector<int> coord;
        coord.push_back(x);
        coord.push_back(y - i);
        coord.push_back(distance++);
        wire1.push_back(coord);
      }
      y = y - spaces;
    }
    std::cin >> next;
    if (next == ';'){
      break;
    }
    // std::cout << "WIRE1" << std::endl;
  }

  // std::cout << "end" << std::endl;

  int lowest = -1;

  for (int i = 0; i < wire0.size(); i++){
    for (int j = 0; j < wire1.size(); j++){
      // std::cout << "for loop" << std::endl;

      if (wire0[i][0] == wire1[j][0] && wire0[i][1] == wire1[j][1]){
        std::cout << wire0[i][0] << " " << wire0[i][1] << std::endl;
        if ((wire0[i][2] + wire1[j][2]) < lowest || lowest == -1){
          lowest = wire0[i][2] + wire1[j][2];
        }
      }
    }
  }

  std::cout << lowest << std::endl;
  return 0;
}
