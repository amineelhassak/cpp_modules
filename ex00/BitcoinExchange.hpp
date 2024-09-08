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
		std::ifstream openFile(const char *path);
		int run(int argc, char** argv);
		void exectPrgm(std::ifstream &file);
		void outputCalcul(const std::string &key, double value);
		void parcInputFile(std::ifstream &file);
		BitcoinExchange();
		~BitcoinExchange();
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

