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

template <typename Container>

Container fill_pairs_container(char **av)
{
    Container C;
    // fill container;
    for (int i = 1; av[i] && av[i + 1]; i += 2)
        C.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
    return C;
}

template <typename Container>

Container fill_container(char **av)
{
    Container C;
    // fill container;
    for (int i = 1; av[i]; i++)
        C.push_back(atoi(av[i]));
    return C;
}

template <typename Container>

void print_pairs_container(Container &C)
{
    std::cout << "container pairs: \n";
    for (size_t i = 0; i < C.size() ; i++)
        std::cout << "pair "<< i + 1 << ": " << C.at(i).first << " " << C.at(i).second << std::endl;
}

template <typename Container>

void print_container(Container &C)
{
    for (size_t i = 0; i < C.size() ; i++)
        std::cout << C.at(i) << " ";
    std::cout << std::endl;
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
    std::vector <int> my_vec = fill_container<std::vector<int> >(av);
    std::vector <std::pair<int, int> > vec = fill_pairs_container<std::vector<std::pair<int, int> > > (av);
    std::cout << "before: ";
    print_container(my_vec);
    // sort two elements of each pair of a container;
    for (size_t i = 0; i < vec.size(); i++)
        sort_two(vec.at(i).first, vec.at(i).second);
    // print_pairs_container(vec);
    std::vector <int> largest;
    for (size_t i = 0; i < vec.size(); i++)
        largest.push_back(vec.at(i).second);
    std::vector <int> smallest;
    for (size_t i = 0; i < vec.size(); i++)
        smallest.push_back(vec.at(i).first);
    // sort one of them (largest);
    sort(largest.begin(), largest.end());
    // insert elements from the unsorted container to the sorted container using lower_bound;
    std::vector <int>::iterator b = smallest.begin();
    std::vector <int>::iterator it;
    while(b != smallest.end())
    {
        it = lower_bound(largest.begin(), largest.end(), *b);
        largest.insert(it, *b);
        b++;
    }
    if (my_vec.size() % 2)
        largest.push_back(*(my_vec.end() - 1));
    std::cout << "After: ";
    print_container(largest);
    return 0;
}