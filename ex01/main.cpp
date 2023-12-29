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
    int result = 0;
    int array[2];
    for (int i = 0; av[1][i]; i++)
    {
        if(isdigit(av[1][i]))
            st.push(atoi(&av[1][i]));
        else if (is_operator(av[1][i]))
        {
            if(st.size() < 2)
            {
                std::cerr << "Error\n";
                return 0;
            }
            array[0] = st.top();
            st.pop();
            array[1] = st.top();
            st.pop();
            if (av[1][i] == '+')
                result = array[1] + array[0];
            else if (av[1][i] == '-')
                result = array[1] - array[0];
            else if (av[1][i] == '*')
                result = array[1] * array[0];
            else if (av[1][i] == '/')
                result = array[1] / array[0];
            st.push(result);
        }
    }
    if (st.size() == 1)
        std::cout << result << std::endl;
    return 0;
}