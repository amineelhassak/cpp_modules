#pragma once

#include <list>
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <deque>

class Span
{
private:
    unsigned int _maxSize;
    std::list<int> _numbers;
    Span();
public:
    Span(const Span &other);
    Span& operator=(const Span &pther);
    Span(unsigned int N);
    std::list<int> getNumbers(void) const;
    unsigned int getMaxSize() const;
    
    ~Span();

    void addNumber(int number);
    void addNumbers(std::list<int>::iterator itbegin, std::list<int>::iterator itend);
    void addNumbers(std::list<int>::const_iterator itbegin, std::list<int>::const_iterator itend);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    class MaxSizeExceededException : public std::exception {
        public:
            const char* what() const throw();
    };
    class NotEnoughNumbersException : public std::exception {
    public:
        const char* what() const throw();
    };
};