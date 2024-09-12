#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

const char* BitcoinExchange::NotOpenFileException::what() const throw()
{
    return ("Error: could not open file.");
}

const char* BitcoinExchange::ERRORPARCEXCEPTION::what() const throw()
{
    return ("Error parsing file");
}

int    leapYear(int year)
{
    return (!(year % 4) && (year % 100) && (year % 400));
}

int getDaysInMonth(int year, int month)
{
    switch (month)
    {
        case 1: return 31;
        case 2: return leapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
    return (true);
}

void BitcoinExchange::openFile(const char *path, std::ifstream &file)
{
    file.open(path);
    if (!file.is_open())
        throw NotOpenFileException();
}

void BitcoinExchange::readDataFile(std::ifstream& file)
{
    std::string line;
    std::string key;
    double value;

    if (!std::getline(file, line) || line != "date,exchange_rate")
        throw ERRORPARCEXCEPTION();

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        if (!std::getline(ss, key, ','))
            throw ERRORPARCEXCEPTION();
        ss >> value;
        dataMap[key] = value;
    }
}

int isDouble(const std::string& str)
{
    int dotCount;
    
    dotCount = 0;
    if (str.empty())
        return (-1);
    if (str[0] == '-')
        return (-2);
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(*it) && *it != '.')
            return (-3);
        if (*it == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return (-3);
        }
    }
    return (1);
}


bool isInteger(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
        if (!std::isdigit(*it) && *it != '.')
            return (false);
    return (true);
}

int parcFirstPart(const std::string& firstpart)
{
    std::stringstream ss(firstpart);
    std::string string;
    int year, month, day;

    if (!std::getline(ss, string, '-') || !isInteger(string)\
         || string.size() != 4 || !(std::stringstream(string) >> year))
        return (false);
    if (!std::getline(ss, string, '-') || !isInteger(string) ||\
         string.size() != 2 || !(std::stringstream(string) >> month))
        return (false);
    if (!std::getline(ss, string, ' ') || !isInteger(string) \
        || string.size() != 2 || !(std::stringstream(string) >> day))
        return (false);
    if (std::getline(ss, string) && !string.empty())
        return (false);
    if ((day > getDaysInMonth(year, month)) ||(day <= 0))
        return (false);
    return (true);
}


void BitcoinExchange::outputCalcul(const std::string& key, double value)
{
    std::map<std::string, double>::iterator it = dataMap.find(key);
    if (it != dataMap.end())
        std::cout << "[" << key << "] => " << value << " = " << value * it->second << std::endl;
    else
    {
        std::map<std::string, double>::reverse_iterator it = dataMap.rbegin();
        for (; it != dataMap.rend() && key <= it->first ; it++){}
        std::cout << "[" << key << "] => " << value << " = " << value * it->second << std::endl;
    }
}

void BitcoinExchange::exectPrgm(std::ifstream& file)
{
    std::string line;
    double      value;
    std::string firstPart, valuePart;
    int         check;

    if (!std::getline(file, line) || line != "date | value")
        throw std::runtime_error("Error in first line of input file");

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        if (!std::getline(ss, firstPart, '|') || !std::getline(ss, valuePart))
        {
            std::cerr << "Error: Bad input line format" << std::endl;
            continue;
        }
        firstPart.erase(firstPart.find_last_not_of(" \n\r\t") + 1);
        valuePart.erase(0, valuePart.find_first_not_of(" \n\r\t"));
    
        if (!parcFirstPart(firstPart))
        {
            std::cerr << "Error: Bad input => " << firstPart << std::endl;
            continue;
        }
        check = isDouble(valuePart);
        switch (check)
        {
            case -1:
                std::cerr << "Error: Bad input => " << firstPart << std::endl;
                break;
            case -2:
                std::cerr << "Error: not a positive number." << std::endl;
                break;
            case -3:
                std::cerr << "Error: Bad input => " << firstPart << std::endl;
                break;
            default:
                std::stringstream(valuePart) >> value;
                if (value > 1000  || value < INT_MIN)
                    std::cerr << "Error: too large a number." << std::endl;
                else
                    outputCalcul(firstPart, value);
                break;
        }
    }
}

int BitcoinExchange::run(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }

    try {
        std::ifstream file;openFile(argv[1], file);
        std::ifstream db;openFile("data.csv", db);
        readDataFile(db);
        exectPrgm(file);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
