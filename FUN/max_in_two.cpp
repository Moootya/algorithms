#include <iostream>

int max_in_two(int a, int b)
{
    return (a > b)? a : b;
}





int main(void)
{

    int a, b;

    std::cin >> a >> b;
    std:: cout << max_in_two(a, b) << std::endl;

    return 0;
}

