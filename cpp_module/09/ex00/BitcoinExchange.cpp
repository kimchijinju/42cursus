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
  while (std::getline(input, line))
  {
    std::pair<std::string, double> priceByDate = split(line, ',');
//  struct tm tm;
//    memset(&tm, 0, sizeof(struct tm));
//    strptime(priceByDate.first.c_str(), "%YYYY-%mm-%dd", &tm);
//    printf("%d/%d/%d %d:%d:%d\n",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
//           tm.tm_hour, tm.tm_min, tm.tm_sec);
//    std::pair<struct tm, double> priceByTime =

    bitcoinPriceMap_.insert(priceByDate);
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

  std::string line;
  while (std::getline(input, line))
  {
    std::pair<std::string, double> numberByDate = split(line, '|');
    if (!isValidLine(numberByDate, line))
      continue;
    std::string &date = numberByDate.first;
    double &number = numberByDate.second;
    double price = bitcoinPriceMap_.lower_bound(date)->second;

    std::cout << date << " => " << number << " = " << number * price << '\n';
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
