#include "BitcoinExchange.hpp"

int check_val(float value)
{
    if (value < 0)
        return -1;
    else if (value > 1000)
        return -2;
    return 1;
}

std::string bad_val(float value)
{
    if (value < 0)
        return "Error: not a positive number.\n";
    else if (value > 1000)
        return "Error: too large a number.\n";
    return 0;
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
    while(dline[i] == ' ')
        i++;
    float value = atof(&dline[i]);
    return value;
}

std::multimap<std::string, float> check_fill_map(int ac, char *av)
{
    std::ifstream InputFile(av);
    if(!InputFile.is_open() || ac != 2)
    {
        std::cerr << "Error: could not open file.\n";
    }
    std::string iline;
    std::multimap<std::string, float> m;
    getline(InputFile, iline); //skip the first line "date | value";
    while(getline(InputFile, iline))
    {
        std::string date = iline.substr(0, 10);
        float value = get_value(iline);
        m.insert(std::pair<std::string, float>(date, value));
    }
    InputFile.close();
    return m;
}

int main(int ac, char **av)
{
    std::multimap<std::string, float> m;
    m = check_fill_map(ac, av[1]);
    std::multimap<std::string, float>::iterator it = m.begin();
    while (it != m.end())
    {
        if(check_val(it->second) == -1)
        {
            std::cout << "Error: not a positive number.\n";
            it++;
            continue;
        }
        else if(check_val(it->second) == -2)
        {
            std::cout << "Error: too large a number.\n";
            it++;
            continue;
        }
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }
    return 0;
}