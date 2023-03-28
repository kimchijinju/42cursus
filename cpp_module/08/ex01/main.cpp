//
// Created by Hanbin Kim on 3/22/23.
#include <iostream>
#include "Span.hpp"


int main()
{
  vector<int> generate;
  srand(time(NULL));
  for (int i = 0; i < 10; ++i)
  {
    generate.push_back(rand() % 100);
  }

  Span span(100);
  span.addNumber(7);
  span.addNumber(5);
  span.addNumber(3);
  span.addNumber(1);
  span.printStorage();
  span.addNumber(generate.begin(), generate.end());
  span.printStorage();
  std::cout << "short : " << span.shortestSpan() << "\nlong : " << span.longestSpan() << '\n';
}