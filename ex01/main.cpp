#include "RPN.hpp"

int is_operator(char av1)
{
    if (av1 == '+' || av1 == '-' || av1 == '*' || av1 == '/')
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: bad number of arguments.\n";
        return 0;
    }
    std::stack<int> st;
    // int result = 0;
    for (int i = 0; av[1][i]; i++)
    {
        if(isdigit(av[1][i]))
        {
            st.push(atoi(&av[1][i]));
            std::cout << st.top() << std::endl;
        }
        else if (is_operator(av[1][i]))
        {
            st.push(av[1][i]);
            std::cout << st.top() << std::endl;
        }
    }
    return 0;
}