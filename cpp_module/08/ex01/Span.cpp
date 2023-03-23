//
// Created by Hanbin Kim on 3/20/23.
//

#include <iostream>
#include <stdexcept>
#include "Span.hpp"

Span::Span(unsigned int N) : storage_(std::vector<int>()), size_(N) {}

Span::~Span() {}

Span::Span(const Span &span) : storage_(span.storage_), size_(span.size_) {}

Span &Span::operator=(const Span &span)
{
  if (this == &span)
    return *this;
  storage_ = span.storage_;
  size_ = span.size_;
  return *this;
}

void Span::addNumber(int number)
{
  if (storage_.size() >= size_)
    throw std::out_of_range("Span : Check range.");
  storage_.push_back(number);
}

int Span::shortestSpan() const
{
  if (storage_.size() <= 1)
    throw std::out_of_range("Span : Can't find.");

  std::vector<int> v(storage_);
  std::sort(v.begin(), v.end());

  int min = INT_MAX;
  for (vector<int>::iterator it = v.begin(); it != storage_.end(); ++it)
  {
    vector<int>::iterator next = it + 1;
    if (next == v.end())
      break ;
    int distance = *next - *it;
    if (distance < min)
      min = distance;
  }
  return min;
}

int Span::longestSpan() const
{
  if (storage_.size() <= 1)
    throw std::out_of_range("Span : Can't find.");
  return *std::max_element(storage_.begin(), storage_.end()) - *std::min_element(storage_.begin(), storage_.end());
}

void Span::printStorage() const
{
  std::vector<int> v(storage_);

  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << '\n';

}