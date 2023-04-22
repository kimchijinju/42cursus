//
// Created by Hanbin Kim on 4/22/23.
//

#ifndef INC_09_EX00_BITCOINEXCHANGE_HPP_
#define INC_09_EX00_BITCOINEXCHANGE_HPP_

#include <map>
#include <string>

class BitcoinExchange
{
 public:
  BitcoinExchange();
  void csvParser(const char *filename);
  void inputParser(const char *filename);
  void printExchange();

  std::map<std::string, double> bitcoinPriceMap_;

  std::pair<std::string, double> split(std::string line, char separate);
  bool isValidLine(std::pair<std::string, double> priceByDate, std::string &line);
  bool isValidDate(std::string &date);
};

#endif //INC_09_EX00_BITCOINEXCHANGE_HPP_
