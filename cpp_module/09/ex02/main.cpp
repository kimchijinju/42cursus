//
// Created by Hanbin Kim on 4/24/23.
//

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <sys/time.h>
#include "PmergeMe.hpp"

bool isNumber(const std::string &str) {
  for (size_t i = 0; i < str.length(); ++i) {
    if (!isdigit(str[i]))
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  std::stringstream print_buffer;
  std::vector<int> vector;
  std::deque<int> deque;

  for (int i = 1; i < argc; ++i) {
    if (!isNumber(argv[i])) {
      std::cout << "error\n";
      return 1;
    }
    vector.push_back(std::atoi(argv[i]));
    deque.push_back(std::atoi(argv[i]));
  }
  Sorter sorter(vector, deque);
  print_buffer << "Before vector: ";
  for (size_t i = 0; i < sorter.before_vector_.size(); ++i) {
    print_buffer << sorter.before_vector_[i] << " ";
  }
  print_buffer << '\n';

  print_buffer << "Before deque: ";
  for (size_t i = 0; i < sorter.before_deque_.size(); ++i) {
    print_buffer << sorter.before_deque_[i] << " ";
  }
  print_buffer << '\n';

  struct timeval before_time_vector;
  gettimeofday(&before_time_vector, NULL);
  sorter.mergeInsertionSortVector();
  struct timeval after_time_vector;
  gettimeofday(&after_time_vector, NULL);

  struct timeval before_time_deque;
  gettimeofday(&before_time_deque, NULL);
  sorter.mergeInsertionSortDeque();
  struct timeval after_time_deque;
  gettimeofday(&after_time_deque, NULL);


  print_buffer << "After vector:  ";
  for (size_t i = 0; i < sorter.after_vector_.size(); ++i) {
    print_buffer << sorter.after_vector_[i] << " ";
  }
  print_buffer << '\n';

  print_buffer << "After deque: ";
  for (size_t i = 0; i < sorter.after_deque_.size(); ++i) {
    print_buffer << sorter.after_deque_[i] << " ";
  }
  print_buffer << "\nTime to process a range of "
               << sorter.after_vector_.size()
               << " elements with std::vector : "
               << (after_time_vector.tv_sec - before_time_vector.tv_sec) * 1000000 + (after_time_vector.tv_usec - before_time_vector.tv_usec)
               << "us";
  print_buffer << "\nTime to process a range of "
               << sorter.after_deque_.size()
               << " elements with std::deque : "
               << (after_time_deque.tv_sec - before_time_deque.tv_sec) * 1000000 + (after_time_deque.tv_usec - before_time_deque.tv_usec)
               << "us";
  std::cout << print_buffer.str() << '\n';
}


