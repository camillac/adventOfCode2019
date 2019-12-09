#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cctype>
#include <vector>

void print_vector(std::vector<int> nums){
  for (int i = 0; i < nums.size(); i++){
    std::cout << nums[i] << ",";
    if (i%4 == 3){
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

int program(std::vector<int> nums, int * rel){
  std::cout << *rel << std::endl;

  int input = 0;
  int num_vals = 2;
  int param1;
  int param2;
  // int param3;

  for (int i = 0; i < nums.size(); i += num_vals){
    // std::cout << *rel << std::endl;

    // ----- 1 ------

    if (nums[i] % 10 == 1){
      // std::cout << "OPCODE 1 " << nums[i] << std::endl;
      if (((nums[i] % 1000) / 100) == 0){
        // std::cout << "param 1 " << param1 << std::endl;
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        // std::cout << "param 1 " << param1 << std::endl;
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;
      }

      if (((nums[i] % 10000) / 1000) == 0){
        // std::cout << "param 2 " << param2 << std::endl;
        param2 = nums[nums[i+2]];
      }
      else if (((nums[i] % 10000) / 1000) == 1) {
        // std::cout << "param 2 " << param2 << std::endl;
        param2 = nums[i+2];
      }
      else if (((nums[i] % 10000) / 1000) == 2){
        param2 = nums[nums[i+2]] + *rel;

      }

      nums[nums[i+3]] = param1 + param2;
      num_vals = 4;
      // std::cout << "i: " << i << std::endl;
    }


    // ----- 2 ------

    else if (nums[i] % 10 == 2){
      // std::cout << "OPCODE 2 " << nums[i] << std::endl;

      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else if (((nums[i] % 10000) / 1000) == 1) {
        param2 = nums[i+2];
      }
      else if (((nums[i] % 10000) / 1000) == 2){
        param2 = nums[nums[i+2]] + *rel;
      }


      nums[nums[i+3]] = param1 * param2;
      num_vals = 4;
    }


    // ----- 3 ------

    else if (nums[i] % 10 == 3){
      // std::cin >> input;
      // std::cout << "OPCODE 3 " << nums[i] << std::endl;

      // std::cout << "3: INPUT " << input << std::endl;
      nums[nums[i+1]] = input;
      num_vals = 2;

    }


    // ----- 4 ------

    else if (nums[i] % 10 == 4){
      // std::cout << "OPCODE 4 " << nums[i] << std::endl;
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;

      }
      std::cout << "4: " << param1 << std::endl;

      num_vals = 2;
      // print_vector(nums);
      return param1;
    }


    // ----- 5 ------

    else if (nums[i] % 10 == 5){
      // std::cout << "OPCODE 5 " << nums[i] << std::endl;
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;

      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else if (((nums[i] % 10000) / 1000) == 1) {
        param2 = nums[i+2];
      }
      else if (((nums[i] % 10000) / 1000) == 2){
        param2 = nums[nums[i+2]] + *rel;

      }


      if (param1 != 0){
        i = param2;
        num_vals = 0;
      }
      else {
        num_vals = 3;
      }
    }


    // ----- 6 ------

    else if (nums[i] % 10 == 6){
      // std::cout << "OPCODE 6 " << nums[i] << std::endl;

      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;

      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else if (((nums[i] % 10000) / 1000) == 1) {
        param2 = nums[i+2];
      }
      else if (((nums[i] % 10000) / 1000) == 2){
        param2 = nums[nums[i+2]] + *rel;

      }


      if (param1 == 0){
        i = param2;
        num_vals = 0;
      }
      else {
        num_vals = 3;
      }
    }


    // ----- 7 ------

    else if (nums[i] % 10 == 7){
      // std::cout << "OPCODE 7 " << nums[i] << std::endl;

      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;

      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else if (((nums[i] % 10000) / 1000) == 1) {
        param2 = nums[i+2];
      }
      else if (((nums[i] % 10000) / 1000) == 2){
        param2 = nums[nums[i+2]] + *rel;

      }


      if (param1 < param2){
        nums[nums[i+3]] = 1;
      }
      else {
        nums[nums[i+3]] = 0;
      }
      num_vals = 4;
    }


    // ----- 8 ------

    else if (nums[i] % 10 == 8){
      // std::cout << "OPCODE 8 " << nums[i] << std::endl;

      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;

      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else if (((nums[i] % 10000) / 1000) == 1) {
        param2 = nums[i+2];
      }
      else if (((nums[i] % 10000) / 1000) == 2){
        param2 = nums[nums[i+2]] + *rel;

      }

      if (param1 < param2){
        nums[nums[i+3]] = 1;
      }
      else {
        nums[nums[i+3]] = 0;
      }

      if (param1 == param2){
        nums[nums[i+3]] = 1;
      }
      else {
        nums[nums[i+3]] = 0;
      }
      num_vals = 4;
    }

    else if (nums[i] % 10 == 9){
      // std::cout << "OPCODE 9 " << nums[i] << std::endl;

      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else if (((nums[i] % 1000) / 100) == 1){
        param1 = nums[i+1];
      }
      else if (((nums[i] % 1000) / 100) == 2){
        param1 = nums[nums[i+1]] + *rel;
      }

      *rel += param1;


      num_vals = 2;

    }

    // ----- 99 -----

    else if (nums[i] == 99){
      // std::cout << "OPCODE 99 " << nums[i] << std::endl;
      // std::cout << "i: " << i << std::endl;

      std::cout << "99 END: " << std::endl;
      return 99;
    }
    else {
      std::cout << "ERROR: UNIDENTIFIED OPCODE " << nums[i] << " i: " << i << std::endl;
      return -1;
    }
  }
  return 0;
}

int main(){


  int input;
  char comma;
  std::vector<int> nums;

  while(std::cin >> input) {
    std::cin >> comma;
    nums.push_back(input);
  }

  for (int i = 0; i < 100000000; i++){
    nums.push_back(0);
  }

  // for (int i = 0; i < 100; i++){
  //   nums[1] = i;
  //   for (int j = 0; j < 100; j++){
  //     nums[2] = j;
  //     if (program(nums) == 19690720){
  //       std::cout << "CORRECT! " << i << " " << j << std::endl;
  //       std::cout << "Answer: " << (100 * i) + j << std::endl;
  //     }
  //   }
  // }

  int * rel = new int;
  rel = 0;

  program(nums, rel);

  delete rel;

  return 0;
}
