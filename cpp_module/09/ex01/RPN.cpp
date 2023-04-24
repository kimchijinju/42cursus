//
// Created by Hanbin Kim on 4/24/23.
//

#include <iostream>
#include "RPN.hpp"

bool isAllowCharacter(char i);
bool isOperator(char i);
void calculation(std::stack<int> &numbers, char oper);

void calculator(std::string &input)
{
  std::stack<int> numbers;

  for (std::string::iterator it = input.begin(); it != input.end(); ++it)
  {
    if (!isAllowCharacter(*it))
    {
      Error();
    }
    if (numbers.size() < 2 && isOperator(*it))
    {
      Error();
    }
    if (isdigit(*it))
    {
      numbers.push(*it - '0');
    }
    if (isOperator(*it))
    {
      calculation(numbers, *it);
    }
  }
  std::cout << numbers.top() << '\n';
}

void calculation(std::stack<int> &numbers, char oper)
{
  int b = numbers.top();
  numbers.pop();
  int a = numbers.top();
  numbers.pop();

  int result = 0;
  switch (oper)
  {
    case '+': result = a + b;
      break;
    case '-': result = a - b;
      break;
    case '*': result = a * b;
      break;
    case '/':
      if (b == 0)
      {
        Error();
      }
      result = a / b;
      break;
  }
  numbers.push(result);
}

bool isOperator(char i)
{
  return i == '+' || i == '-' || i == '*' || i == '/';
}

bool isAllowCharacter(char i)
{
  return isdigit(i) || isblank(i) || isOperator(i);
}

void Error()
{
  std::cerr << "Error\n";
  exit(1);
}