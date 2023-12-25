#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file.\n";
        return 0;
    }
    
    // std::map<std::string,int> m;
    // m.insert(std::pair<std::string, int>("jj", 5));
    // std::map<std::string, int>::iterator it = m.begin();
    // while(it != m.end())
    // {
    //     std::cout << it->first << ": " << it->second << std::endl;
    //     it++;
    // }
    // return 0;
}