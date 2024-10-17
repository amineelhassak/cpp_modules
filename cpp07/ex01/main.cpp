#include "iter.hpp"

void affichage(int const &n)
{
    std::cout << (2 * n) << std::endl;
}

int main( void )
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;
    iter(arr, len, affichage);
    return 0;
}
