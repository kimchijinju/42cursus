//
// Created by Hanbin Kim on 4/24/23.
//

#include "PmergeMe.hpp"

Sorter::Sorter(std::vector<int> &v, std::deque<int> &d)
    : before_vector_(v), before_deque_(d), vector_comparator_(before_vector_), deque_comparator_(before_deque_) {}

Sorter::VectorComparator::VectorComparator(std::vector<int> &origin) : origin_(origin) {}

Sorter::VectorComparator::VectorComparator(const VectorComparator &comparator) : origin_(comparator.origin_) {}

Sorter::VectorComparator::~VectorComparator() {}

bool Sorter::VectorComparator::operator()(int a, int b) {
  return origin_[a] < origin_[b];
}

Sorter::DequeComparator::DequeComparator(std::deque<int> &origin) : origin_(origin) {}

Sorter::DequeComparator::DequeComparator(const Sorter::DequeComparator &comparator) : origin_(comparator.origin_) {}

Sorter::DequeComparator::~DequeComparator() {}

bool Sorter::DequeComparator::operator()(int a, int b) {
  return origin_[a] < origin_[b];
}

Sorter::~Sorter() {}

std::vector<int> createMainChain(size_t mid, std::vector<int> &origin, std::vector<int> &index) {
  std::vector<int> main_chain(origin.size(), -1);

  for (int i = 0; i < mid; ++i) {
    if (origin[index[i]] < origin[index[i + mid]]) {
      std::swap(index[i], index[i + mid]);
    }
    main_chain[index[i]] = index[i + mid];
  }
  return main_chain;
}

void Sorter::sorting(size_t size, std::vector<int> &origin, std::vector<int> &index) {
  if (size <= 1) {
    return;
  }
  // catch straggler
  int straggler;
  bool has_straggler = size % 2 == 1;
  if (has_straggler) {
    straggler = index[size - 1];
  }
  std::vector<int> main_chain(createMainChain(size / 2, origin, index));
  sorting(size / 2, origin, index);

  size_t insert_size = size / 2;
  std::vector<int> pend_element;
  for (size_t i = 0; i < insert_size; ++i) {
    //여기서 에러남
    pend_element.push_back(main_chain[index[i]]);
  }
  index.insert(index.begin(), *pend_element.begin());
  pend_element.erase(pend_element.begin());

  int pending_count = pend_element.size();
  int sorted_count = (size / 2) + 1;
  //정렬 후보군 시작값 위치
  int prev_start = 0;
  // 인덱스
  int n = 2;
  int power_of_two = 2;
  // 현재 정렬할 개수(jacob n + 1 - jacob n 수열)
  int curr = 2;
  while (prev_start < pending_count) {
    //index로 들어가야 해서 1씩 뺍니다
    int j = std::min(prev_start + curr - 1, pending_count - 1);
    power_of_two = power_of_two << 1;
    while (j >= prev_start) {
      std::vector<int>::iterator start = index.begin();
      std::vector<int>::iterator end = start + std::min(power_of_two, sorted_count);
      std::vector<int>::iterator insert_point = std::lower_bound(start, end, pend_element[j], vector_comparator_);
      index.insert(insert_point, pend_element[j]);
      ++sorted_count;
      --j;
    }
    prev_start = std::min(prev_start + curr, pending_count);
    curr = power_of_two - curr;
  }
  if (has_straggler) {
    index.insert(std::lower_bound(index.begin(), index.begin() + size - 1, straggler, vector_comparator_), straggler);
  }
}

void Sorter::mergeInsertionSortVector() {
  std::vector<int> index;

  for (int i = 0; i < before_vector_.size(); ++i) {
    index.push_back(i);
  }

  sorting(before_vector_.size(), before_vector_, index);

  for (int i = 0; i < before_vector_.size(); ++i) {
    after_vector_.push_back(before_vector_[index[i]]);
  }
}

std::deque<int> createMainChain(size_t mid, std::deque<int> &origin, std::deque<int> &index) {
  std::deque<int> main_chain(origin.size(), -1);

  for (int i = 0; i < mid; ++i) {
    if (origin[index[i]] < origin[index[i + mid]]) {
      std::swap(index[i], index[i + mid]);
    }
    main_chain[index[i]] = index[i + mid];
  }
  return main_chain;
}

void Sorter::sorting(size_t size, std::deque<int> &origin, std::deque<int> &index) {
  if (size <= 1) {
    return;
  }
  // catch straggler
  int straggler;
  bool has_straggler = size % 2 == 1;
  if (has_straggler) {
    straggler = index[size - 1];
  }
  std::deque<int> main_chain(createMainChain(size / 2, origin, index));
  sorting(size / 2, origin, index);

  size_t insert_size = size / 2;
  std::vector<int> pend_element;
  for (size_t i = 0; i < insert_size; ++i) {
    //여기서 에러남
    pend_element.push_back(main_chain[index[i]]);
  }
  index.insert(index.begin(), *pend_element.begin());
  pend_element.erase(pend_element.begin());

  int pending_count = pend_element.size();
  int sorted_count = (size / 2) + 1;
  //정렬 후보군 시작값 위치
  int prev_start = 0;
  // 인덱스
  int n = 2;
  int power_of_two = 2;
  // 현재 정렬할 개수(jacob n + 1 - jacob n 수열)
  int curr = 2;
  while (prev_start < pending_count) {
    //index로 들어가야 해서 1씩 뺍니다
    int j = std::min(prev_start + curr - 1, pending_count - 1);
    power_of_two = power_of_two << 1;
    while (j >= prev_start) {
      std::deque<int>::iterator start = index.begin();
      std::deque<int>::iterator end = start + std::min(power_of_two, sorted_count);
      std::deque<int>::iterator insert_point = std::lower_bound(start, end, pend_element[j], deque_comparator_);
      index.insert(insert_point, pend_element[j]);
      ++sorted_count;
      --j;
    }
    prev_start = std::min(prev_start + curr, pending_count);
    curr = power_of_two - curr;
  }
  if (has_straggler) {
    index.insert(std::lower_bound(index.begin(), index.begin() + size - 1, straggler, deque_comparator_), straggler);
  }
}

void Sorter::mergeInsertionSortDeque() {
  std::deque<int> index;

  for (int i = 0; i < before_deque_.size(); ++i) {
    index.push_back(i);
  }

  sorting(before_deque_.size(), before_deque_, index);

  for (int i = 0; i < before_deque_.size(); ++i) {
    after_deque_.push_back(before_deque_[index[i]]);
  }
}

