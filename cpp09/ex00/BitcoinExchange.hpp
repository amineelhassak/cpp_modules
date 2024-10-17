#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <map>
#include <iterator>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string ,double>dataMap;
	public:
		void readDataFile(std::ifstream &file);
		void openFile(const char *path, std::ifstream &file);
		int run(int argc, char** argv);
		void exectPrgm(std::ifstream &file);
		void outputCalcul(const std::string &key, double value);
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		class NotOpenFileException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class ERRORPARCEXCEPTION : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

