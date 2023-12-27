#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

int check_val(float value);
float get_value(std::string &iline);
float get_data_value(std::string &dline);

typedef std::map<std::string, float> map;

class BitcoinExchange
{
private:
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
};

#endif