#include "BitcoinExchange.hpp"

int check_val(float value)
{
    if (value < 0)
        return -1;
    else if (value > 1000)
        return -2;
    return 1;
}

float get_value(std::string &iline)
{
    int i = 0;
    while(iline[i] && iline[i] != '|')
        i++;
    if(iline[i])
        i++;
    while(iline[i] == ' ')
        i++;
    float value = atof(&iline[i]);
    return value;
}

float get_data_value(std::string &dline)
{
    int i = 0;
    while(dline[i] && dline[i] != ',')
        i++;
    if(dline[i])
        i++;
    while(dline[i] == ' ')
        i++;
    float value = atof(&dline[i]);
    return value;
}