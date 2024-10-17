#include "Span.hpp"

Span::Span(const Span &other)
{
    *this = other;
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to find a span.";
}

Span::Span(unsigned int N) : _maxSize(N){}

std::list<int> Span::getNumbers(void) const
{
    return this->_numbers;
}

unsigned int Span::getMaxSize() const
{
    return this->_maxSize;
}

Span& Span::operator = (const Span &other)
{
    if (this != &other)
    {
        this->_numbers.clear();
        this->_numbers = other.getNumbers();
        this->_maxSize = other.getMaxSize();
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (this->_numbers.size() >= this->_maxSize)
        throw MaxSizeExceededException();
    this->_numbers.push_back(number);
}

unsigned int Span::shortestSpan()
{
    (this->_numbers.size() < 2) && (throw NotEnoughNumbersException(), 0);
    int span;
    this->_numbers.sort();
    std::deque<int> dr;
    std::list<int>::const_iterator it = this->_numbers.begin();
    std::list<int>::const_iterator next_it = ++this->_numbers.begin();
    while (next_it != this->_numbers.end())
    {
        span = abs(*next_it - *it);
        dr.push_back(span);
        ++it;
        ++next_it;
    }
    return (std::sort(dr.begin(), dr.end()), *dr.begin());
}

void Span::addNumbers(std::list<int>::iterator itbegin, std::list<int>::iterator itend)
{
    unsigned int distance = std::distance(itbegin, itend);
    if (this->_numbers.size() + distance > this->_maxSize)
        throw MaxSizeExceededException();
    _numbers.insert(_numbers.end(), itbegin, itend); 
}

void Span::addNumbers(std::list<int>::const_iterator itbegin, std::list<int>::const_iterator itend)
{
    unsigned int distance = std::distance(itbegin, itend);
    if (this->_numbers.size() + distance > this->_maxSize)
        throw MaxSizeExceededException();
    _numbers.insert(_numbers.end(), itbegin, itend); 
    std::copy(this->_numbers.begin(), this->_numbers.end(), std::ostream_iterator<int>(std::cout, "|"));std::cout << std::endl;
}

unsigned int Span::longestSpan()
{
    (this->_numbers.size() < 2) && (throw NotEnoughNumbersException(), 0);
    return (this->_numbers.sort(), this->_numbers.back() - *_numbers.begin());
}

const char* Span::MaxSizeExceededException::what() const throw() {
    return "Cannot add more numbers: maximum size exceeded.";
}

Span::~Span() {}
