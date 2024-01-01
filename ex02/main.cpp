#include "PmergeMe.hpp"

int check_args(int ac, char **av)
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

void sort_two(int &a, int &b)
{
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
}

int main(int ac, char **av)
{
    if (!check_args(ac, av))
        return 0;
    sort<std::vector <int>, std::vector <std::pair<int, int> > >(ac, av, "std::vector");
    sort<std::deque <int>, std::deque <std::pair<int, int> > >(ac, av, "std::deque");
    return 0;
}
