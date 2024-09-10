#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: <program> <input>" << std::endl;
        return (1);
    }
    try
    {
        run(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}