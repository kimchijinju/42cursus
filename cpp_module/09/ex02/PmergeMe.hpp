//
// Created by Hanbin Kim on 4/24/23.
//

#ifndef INC_09_EX02_PMERGEME_HPP_
#define INC_09_EX02_PMERGEME_HPP_

#include <vector>
#include <deque>

typedef std::vector<int>::iterator iterator;

class Sorter {
 public:
  Sorter(std::vector<int> &v, std::deque<int> &d);
  ~Sorter();

  std::vector<int> before_vector_;
  std::vector<int> after_vector_;

  std::deque<int> before_deque_;
  std::deque<int> after_deque_;
  void mergeInsertionSortVector();
  void mergeInsertionSortDeque();

 private:
  class VectorComparator {
   public:
    VectorComparator(std::vector<int> &origin);
    VectorComparator(const VectorComparator &comparator);
    ~VectorComparator();
    bool operator()(int a, int b);
    std::vector<int> &origin_;
   private:
    VectorComparator();
    VectorComparator &operator= (const VectorComparator &comparator);

  };

  class DequeComparator {
   public:
    DequeComparator(std::deque<int> &origin);
    DequeComparator(const DequeComparator &comparator);
    ~DequeComparator();
    bool operator()(int a, int b);
    std::deque<int> &origin_;
   private:
    DequeComparator();
    DequeComparator &operator= (const DequeComparator &comparator);
  };

  VectorComparator vector_comparator_;
  DequeComparator deque_comparator_;
  void sorting(size_t size, std::vector<int> &origin, std::vector<int> &index);
  void sorting(size_t size, std::deque<int> &origin, std::deque<int> &index);

  Sorter(const Sorter &sorter);
  Sorter &operator= (const Sorter &sorter);
};


#endif //INC_09_EX02_PMERGEME_HPP_
