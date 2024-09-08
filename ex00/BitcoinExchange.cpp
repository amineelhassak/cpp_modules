#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

const char* BitcoinExchange::NotOpenFileException::what() const throw() {
    return "Error: could not open file.";
}

const char* BitcoinExchange::ERRORPARCEXCEPTION::what() const throw() {
    return "Error parsing file";
}

int    leapYear(int year) {
    return (!(year % 4) && (year % 100) && (year % 400));
}

int getDaysInMonth(int year, int month) {
    switch (month) {
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
    return (0);
}

std::ifstream BitcoinExchange::openFile(const char* path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw NotOpenFileException();
    }
    return file;
}

void BitcoinExchange::readDataFile(std::ifstream& file) {
    std::string line;
    std::string key;
    double value;

    if (!std::getline(file, line) || line != "date,exchange_rate") {
        throw ERRORPARCEXCEPTION();
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, key, ',');
        ss >> value;
        dataMap[key] = value;
    }
}

int isDouble(const std::string& str) {
    if (str.empty()) return -1;
    if (str[0] == '-') return -2;

    int dotCount = 0;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it) && *it != '.') return -3;
        if (*it == '.') {
            dotCount++;
            if (dotCount > 1) return -3;
        }
    }
    return 1;
}


bool isInteger(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it) && *it != '.')
            return false;
    }
    return true;
}

int parcFirstPart(const std::string& firstpart) {
    std::stringstream ss(firstpart);
    std::string string;
    int year, month, day;

    if (!std::getline(ss, string, '-') || !isInteger(string) || string.size() != 4 || !(std::stringstream(string) >> year)) {
        throw std::runtime_error("Error parsing year");
    }

    if (!std::getline(ss, string, '-') || !isInteger(string) || string.size() != 2 || !(std::stringstream(string) >> month)) {
        throw std::runtime_error("Error parsing month");
    }

    if (!std::getline(ss, string, ' ') || !isInteger(string) || string.size() != 2 || !(std::stringstream(string) >> day)) {
        throw std::runtime_error("Error parsing day");
    }

    if (std::getline(ss, string) && !string.empty()) {
        throw std::runtime_error("Extra data after date");
    }
    if ((day > getDaysInMonth(year, month)) ||(day <= 0))
    {
        return (0);
    }
    return (1);
}


void BitcoinExchange::outputCalcul(const std::string& key, double value) {
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

void BitcoinExchange::parcInputFile(std::ifstream& file) {
    std::string line;
    double value;

    if (!std::getline(file, line) || line != "date | value") {
        throw std::runtime_error("Error in first line of input file");
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string firstPart, valuePart;
        if (!std::getline(ss, firstPart, '|') || !std::getline(ss, valuePart)) {
            std::cerr << "Error: Bad input line format" << std::endl;
            continue;
        }
        firstPart.erase(firstPart.find_last_not_of(" \n\r\t") + 1);
        valuePart.erase(0, valuePart.find_first_not_of(" \n\r\t"));
    
        int checkYDM = parcFirstPart(firstPart);
        if (checkYDM == 0)
        {
            std::cerr << "Error: Bad input => " << firstPart << std::endl;
            continue;
        }
        int check = isDouble(valuePart);
        switch (check) {
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
                if (value > INT_MAX || value < INT_MIN) {
                    std::cerr << "Error: too large a number." << std::endl;
                } else {
                    outputCalcul(firstPart, value);
                }
                break;
        }
    }
}

void BitcoinExchange::exectPrgm(std::ifstream& file) {
    parcInputFile(file);
}

int BitcoinExchange::run(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }

    try {
        std::ifstream file = openFile(argv[1]);
        std::ifstream db = openFile("data.csv");
        readDataFile(db);
        exectPrgm(file);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
