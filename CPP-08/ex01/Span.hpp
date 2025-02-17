#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
#include <iterator> 

class Span
{
	private:
		unsigned int 		_N;
		std::vector<int>	*numbers;
		unsigned int size();

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		//void addNumbers(std::vector<int> begin, std::vector<int> end);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);



		class FullVectorException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class SpanIsNotBigEnoughException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif