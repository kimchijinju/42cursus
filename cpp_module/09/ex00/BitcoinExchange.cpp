//
// Created by Hanbin Kim on 4/22/23.
//

#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"
#include <string>

BitcoinExchange::BitcoinExchange()
{
  csvParser("./data.csv");
}

void BitcoinExchange::csvParser(const char *filename)
{
  std::ifstream input(filename);

  if (input.fail())
  {
    std::cout << "Error: could not open file.\n";
    exit(1);
  }

  std::string line;
  getline(input, line);

  while (std::getline(input, line))
  {
    std::pair<std::string, double> priceByDate = split(line, ',');
    time_t time = getTime(priceByDate.first);
    std::pair<time_t, double> priceByTime = std::make_pair(time, priceByDate.second);
    bitcoinPriceMap_.insert(priceByTime);
  }
}

void BitcoinExchange::inputParser(const char *filename)
{
  std::ifstream input(filename);

  if (input.fail())
  {
    std::cout << "Error: could not open file.\n";
    exit(1);
  }

  std::string header;
  getline(input, header);
  if (header != "date | value")
  {
    std::cout << "Error: incorrect file format.\n";
    exit(1);
  }

  std::string line;
  char buf[11];
  while (std::getline(input, line))
  {
    std::pair<std::string, double> numberByDate = split(line, '|');
    if (!isValidLine(numberByDate, line))
      continue;
    time_t time = getTime(numberByDate.first);
    double number = numberByDate.second;
    double price = (--bitcoinPriceMap_.lower_bound(time))->second;

    struct tm *t = localtime(&time);
    strftime(buf, sizeof(buf), "%Y-%m-%d", t);
    std::cout << buf << " => " << number << " = " << number * price << '\n';
  }
}

std::pair<std::string, double> BitcoinExchange::split(std::string line, char separate)
{
  size_t separate_point = line.find(separate);
  if (separate_point == std::string::npos)
    return std::make_pair("", -1.0);

  std::string date(line.substr(0, separate_point));
  date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
  line.erase(line.begin(), line.begin() + separate_point + 1);

  char *endptr;
  double value = strtod(line.c_str(), &endptr);
  if (line.empty() || *endptr != '\0')
    return std::make_pair("", -1.0);

  return std::make_pair(date, value);
}

bool BitcoinExchange::isValidLine(std::pair<std::string, double> numberByDate, std::string &line)
{
  std::string &date = numberByDate.first;
  double &bitcoinCount = numberByDate.second;

  if (date.empty() && bitcoinCount == -1.0)
  {
    std::cout << "Error: bad input => " << line << '\n';
    return false;
  }
  if (!isValidDate(date))
  {
    std::cout << "Error: bad date format.\n";
    return false;
  }
  if (bitcoinCount < 0.0)
  {
    std::cout << "Error: too small a number. => " << line << '\n';
    return false;
  }
  if (bitcoinCount > 1000.0)
  {
    std::cout << "Error: too large a number. => " << line << '\n';
    return false;
  }
  return true;
}

bool BitcoinExchange::isValidDate(std::string &date)
{
  if (date.length() != 10)
    return false;
  if (!(date[4] == '-' && date[7] == '-'))
    return false;

  if (!(isdigit(date[0]) && isdigit(date[1]) && isdigit(date[2]) && isdigit(date[3])))
    return false;
  if (!(isdigit(date[5]) && isdigit(date[6])))
    return false;
  if (!(isdigit(date[8]) && isdigit(date[9])))
    return false;
  return true;
}

time_t BitcoinExchange::getTime(std::string date)
{
  struct tm tm;
  memset(&tm, 0, sizeof(struct tm));
  strptime(date.c_str(), "%Y-%m-%d", &tm);
  return mktime(&tm);
}
