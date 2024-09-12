#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    BitcoinExchange bitc;
    try
    {
        bitc.run(argc, argv);
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}