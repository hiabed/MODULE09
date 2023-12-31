#include "PmergeMe.hpp"

int check_av(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error\n";
        return (0);
    }
    for (int i = 0; av[i]; i++)
    {
        if(atoi(av[i]) < 0)
        {
            std::cerr << "Error\n";
            return (0);
        }
    }
    return (1);
}

int main(int ac, char **av)
{
    if (!check_av(ac, av))
        return 0;
    return 0;
}