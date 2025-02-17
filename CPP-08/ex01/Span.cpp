#include "Span.hpp"

Span::Span(){
    numbers =  NULL;
    _N = 0;
}

Span::~Span(){
    delete numbers;
}

Span::Span(unsigned int N){
    _N = N;
    numbers = new std::vector<int>;
}

Span::Span(const Span &other){
    *this = other;
}

Span &Span::operator=(const Span &other){
    if (this != &other)
	{
		this->_N = other._N;
		if (this->numbers != NULL)
			delete this->numbers;
		this->numbers = new std::vector<int>(*other.numbers);
	}
	return (*this);    
}

unsigned int Span::size(){
    return (this->numbers->size());
}

void Span::addNumber(int n){
    if (size() >= _N)
        throw Span::FullVectorException();
    numbers->push_back(n);
}

int Span::shortestSpan(){
    int temp;
    int shortest;
    std::vector<int> tempVector(*this->numbers);
    std::sort(tempVector.begin(), tempVector.end());
    if (size() <= 1)
        throw Span::FullVectorException();
    shortest = tempVector[1] - tempVector[0];
    for (size_t i = 2; i < tempVector.size(); i++){
        temp = tempVector[i] - tempVector[i - 1];
        if (temp < shortest)
            shortest = temp;
    }
    return shortest;
}

int Span::longestSpan(){
    std::vector<int> tempVector(*this->numbers);
    std::sort(tempVector.begin(), tempVector.end());
    if (tempVector.size() <= 1)
        throw Span::SpanIsNotBigEnoughException();
    return (tempVector[tempVector.size() - 1] - tempVector[0]);
}

const char *Span::FullVectorException::what() const throw()
{
	return ("There's no space available in this vector");
}
const char *Span::SpanIsNotBigEnoughException::what() const throw()
{
	return ("Vector needs more than 2 params to check the span");
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) + numbers->size() > _N)
        throw Span::FullVectorException();
    numbers->insert(numbers->end(), begin, end);
}

