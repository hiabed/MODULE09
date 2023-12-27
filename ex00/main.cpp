#include "BitcoinExchange.hpp"

map check_fill_map()
{
    std::ifstream DataFile("data.csv");
    if (!DataFile.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        exit(EXIT_FAILURE);
    }
    std::string dline;
    map m;
    getline(DataFile, dline);
    while(getline(DataFile, dline))
    {
        std::string dDate = dline.substr(0, 10);
        float dValue = get_data_value(dline);
        m.insert(std::pair<std::string, float>(dDate, dValue));
    }
    DataFile.close();
    return m;
}

void print_keyVal(map m)
{
    map::iterator it = m.begin();
    while (it != m.end())
    {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    map m;
    m = check_fill_map();
    print_keyVal(m);
    return 0;
}