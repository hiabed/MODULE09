#include "BitcoinExchange.hpp"

void check_val(float value)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number.\n";
    }
    else if (value > 1000)
    {
        std::cout << "Error: too large a number.\n";
    }
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

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file.\n";
        return 0;
    }
    std::ifstream InputFile(av[1]);
    std::ifstream data("data.csv");
    if(!InputFile.is_open() || !data.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        return 0;
    }
    std::string iline;
    std::string dline;
    getline(InputFile, iline); // to skip the first line of av[1] file;
    if (iline != "date | value")
        std::cerr << "Error: bad input => " << iline << std::endl;
    std::map<std::string, float> data_m;
    std::map<std::string, float>::iterator found;
    while(getline(InputFile, iline))
    {
        std::string date = iline.substr(0, 10);
        float value = get_value(iline);
        check_val(value);
        std::map<std::string, float> m;
        m.insert(std::pair<std::string, float>(date, value));

        // getline(data, dline); // to skip the first line of dataBase;
        // std::string data_date = dline.substr(0, 10);
        // float data_value = get_data_value(dline);
        // data_m.insert(std::pair<std::string, float>(data_date, data_value));
        // found = data_m.find(iBeg->first);
        // if(iBeg->first == "2009-02-01")
        // {
        //     std::cout << "the value found is: " << found->first << std::endl;
        //     return 0;
        // }
        // else
        // {
        //     std::cout << "value not found.\n";
        // }
    }
    InputFile.close();
    data.close();
    return 0;
}