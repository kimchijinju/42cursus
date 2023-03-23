//
// Created by Hanbin Kim on 3/20/23.
//

#ifndef INC_08_EX01_SPAN_HPP_
#define INC_08_EX01_SPAN_HPP_

#include <algorithm>
#include <vector>

using std::vector;

class Span
{
 public:
  Span(unsigned int N);
  ~Span();
  Span(const Span &span);
  Span &operator=(const Span &span);
  void addNumber(int number);

  template <typename InputIterator>
  void addNumber(InputIterator begin, InputIterator end)
  {
    while (begin != end)
    {
      storage_.push_back(*begin);
      ++begin;
    }
  }

  void printStorage() const;
  int shortestSpan() const;
  int longestSpan() const;

 private:
  Span();
  vector<int> storage_;
  unsigned int size_;
};

#endif //INC_08_EX01_SPAN_HPP_