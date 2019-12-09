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

int program(std::vector<int> &nums, int phase, int in, bool &done, int &i){

  // std::cout << "PRINTING INPUT FOR PROGRAM: " << in << std::endl;
  int input = 0;
  int counter = 0;

  int temp = 0;
  int num_vals = 2;
  int param1;
  int param2;
  // int param3;

  for (; i < nums.size(); i += num_vals){

    // ----- 1 ------

    if (nums[i] % 10 == 1){
      // std::cout << "OPCODE 1 " << nums[i] << std::endl;
      if (((nums[i] % 1000) / 100) == 0){
        // std::cout << "param 1 " << param1 << std::endl;
        param1 = nums[nums[i+1]];
      }
      else {
        // std::cout << "param 1 " << param1 << std::endl;
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        // std::cout << "param 2 " << param2 << std::endl;
        param2 = nums[nums[i+2]];
      }
      else {
        // std::cout << "param 2 " << param2 << std::endl;
        param2 = nums[i+2];
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
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
      }

      nums[nums[i+3]] = param1 * param2;
      num_vals = 4;
    }


    // ----- 3 ------

    else if (nums[i] % 10 == 3){
      // std::cin >> input;
      // std::cout << "OPCODE 3 " << nums[i] << std::endl;
      if (counter == 0 && phase != -1){
        input = phase;
        counter++;
      }
      else {
        input = in;
      }
      // std::cout << "3: INPUT " << input << std::endl;
      nums[nums[i+1]] = input;
      num_vals = 2;

    }


    // ----- 4 ------

    else if (nums[i] % 10 == 4){
      // std::cout << "OPCODE 4 " << nums[i] << std::endl;
      std::cout << "4: " << nums[nums[i+1]] << std::endl;
      // print_vector(nums);

      temp = i;
      i+= 2;
      return nums[nums[temp+1]];
    }


    // ----- 5 ------

    else if (nums[i] % 10 == 5){
      // std::cout << "OPCODE 5 " << nums[i] << std::endl;
      if (((nums[i] % 1000) / 100) == 0){
        param1 = nums[nums[i+1]];
      }
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
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
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
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
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
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
      else {
        param1 = nums[i+1];
      }
      if (((nums[i] % 10000) / 1000) == 0){
        param2 = nums[nums[i+2]];
      }
      else {
        param2 = nums[i+2];
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

    // ----- 99 -----

    else if (nums[i] == 99){
      // std::cout << "OPCODE 99 " << nums[i] << std::endl;
      // std::cout << "i: " << i << std::endl;

      std::cout << "99 END: " << in << std::endl;
      done = true;
      return in;
    }
    else {
      std::cout << "ERROR: UNIDENTIFIED OPCODE " << nums[i] << " i: " << i << std::endl;
      return -1;
    }
  }
  return 0;
}

// Function to display the array
void display(int  a[], int n)
{
  for (int i = 0; i < n; i++) {
      std::cout << a[i] << "  ";
  }
  std::cout << std::endl;
}

int main(){


  int input;
  char comma;
  std::vector<int> nums;
  std::vector<int> nums0;
  std::vector<int> nums1;
  std::vector<int> nums2;
  std::vector<int> nums3;
  std::vector<int> nums4;


  while(std::cin >> input) {
    std::cin >> comma;
    nums.push_back(input);

  }

  // print_vector(nums);

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

  int in = 0;
  int max = -2000;

  int output = 0;

  int index0 = 0;
  int index1 = 0;
  int index2 = 0;
  int index3 = 0;
  int index4 = 0;


  int a[] = { 5,6,7,8,9 };
  int n = sizeof(a) / sizeof(a[0]);


  bool done;

  // std::cout << program(nums, 5, 0) << std::endl;
  do {
    in = 0;
    done = false;
    index0 = 0;
    index1 = 0;
    index2 = 0;
    index3 = 0;
    index4 = 0;

    for (int x = 0; x < nums.size(); x++){
      nums0.push_back(nums[x]);
      nums1.push_back(nums[x]);
      nums2.push_back(nums[x]);
      nums3.push_back(nums[x]);
      nums4.push_back(nums[x]);
    }

    std::cout << a[0] << a[1] << a[2] << a[3] << a[4] << std::endl;
    output = program(nums4, a[4], program(nums3, a[3], program(nums2, a[2], program(nums1, a[1], program(nums0, a[0], in, done, index0), done, index1), done, index2), done, index3), done, index4);
    // std::cout << "output FIRST: " << output << " "<< done << std::endl;


    while (!done){

      in = output;
      // std::cout << "input " << in << std::endl;

      output = program(nums4, -1, program(nums3, -1, program(nums2, -1, program(nums1, -1, program(nums0, -1, in, done, index0), done, index1), done, index2), done, index3), done, index4);
      // std::cout << "index: " << index0 << std::endl;
      // std::cout << "OUTPUT: " << output << " " << done<< std::endl;
    }
    if (in > max){
      max = in;
    }

    std::cout << "out " << in << " " << output << std::endl;

  } while (std::next_permutation(a, a + n));


  std::cout << "MAX: " << max << std::endl;
  return 0;
}
