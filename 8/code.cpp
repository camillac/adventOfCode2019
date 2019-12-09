#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cctype>
#include <vector>


int main(){

  // std::ifstream fin("input.txt");
  // if (fin.fail()) {
  //   std::cerr << "File cannot be opened for reading." << std::endl;
  //   exit(1); // exit if failed to open the file
  // }

  const int WIDTH = 25;
  const int HEIGHT = 6;

  std::string line;
  std::string all;

  std::vector< std::vector< std::vector<int> > > layer;
  std::vector< std::vector<int> > rows;
  std::vector<int> cols;


  //
  // while(getline(fin,line)){
  //   all += line;
  // }
  std::cin >> all;

  // fin.close();
  // std::cout << all << std::endl;

  for (int i = 0; i < all.length(); i += WIDTH * HEIGHT){
    for (int j = i; j < WIDTH*HEIGHT + i; j+= WIDTH){
      for (int k = j; k < WIDTH + j; k++){
        cols.push_back((int)(all[k]) - 48);
      }
      rows.push_back(cols);
      // std::cout << (int)(all[j]) - 48;
      cols.clear();
    }
    // std::cout << std::endl;
    layer.push_back(rows);
    rows.clear();
  }

  int numZero = 0;
  int fewest = WIDTH*HEIGHT + 1;
  int fewLayer = -1;

  // for (int i = 0; i < layer.size(); i++){
  //   // std::cout << fewest << " " << fewLayer << " " << layer.size() << std::endl;
  //
  //   for (int j = 0; j < HEIGHT; j++){
  //     for (int k = 0; k < WIDTH; k++){
  //       if (layer[i][j][k] == 0){
  //         numZero++;
  //       }
  //     }
  //
  //   }
  //   if (numZero < fewest){
  //     fewest = numZero;
  //     fewLayer = i;
  //   }
  //   numZero = 0;
  // }

  std::cout << fewest << " " << fewLayer << std::endl;

  int image[HEIGHT][WIDTH];
  for (int j = 0; j < HEIGHT; j++){
    for (int k = 0; k < WIDTH; k++){
      image[j][k] = -1;
    }
  }

  int numOne = 0;
  int numTwo = 0;

  for (int i = 0; i < layer.size(); i++){
    for (int j = 0; j < HEIGHT; j++){
      for (int k = 0; k < WIDTH; k++){
        // std::cout << layer[fewLayer][i][j] <<  std::endl;
        if ((image[j][k] != 0 && image[j][k] != 1) || image[j][k] == 2){
          image[j][k] = layer[i][j][k];
        }
      }
    }
  }

  for (int j = 0; j < HEIGHT; j++){
    for (int k = 0; k < WIDTH; k++){
      if (image[j][k] == 2 || image[j][k] == 0){
        std::cout << " ";

      }
      else {
        std::cout << image[j][k];
      }
    }
    std::cout << std::endl;
  }
  // std::cout << numOne << " x " << numTwo << " = " << numOne * numTwo << std::endl;

  return 0;
}
