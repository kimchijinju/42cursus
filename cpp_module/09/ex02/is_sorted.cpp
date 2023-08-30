#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  std::vector<std::string> vec(argv + 1, argv + argc);
  std::vector<int> int_vec;
  for (auto str : vec) {
    int_vec.push_back(std::stoi(str));
  }

  for (int i = 0; i < int_vec.size() - 1; ++i) {
    if (int_vec[i] > int_vec[i + 1]) {
      std::cout << "not sorted" << std::endl;
      return 1;
    }
  }
  std::cout << "sorted" << std::endl;
}