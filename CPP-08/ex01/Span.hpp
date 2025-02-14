#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int 		N;
		std::vector<int>	*numbers;
		unsigned int size();

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &cpy);
		Span &operator=(const Span &cpy);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

        template<typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end){
            if (std::distance(begin, end) + numbers.size() > N)
                throw std::out_of_range("No hay espacio suficiente para agregar todos los números del rango");
            numbers.insert(numbers.end(), begin, end);
        }
}

#endif