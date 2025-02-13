#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array{
    private:
        T   *array;
        unsigned int len;
    public:
        Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		T &operator[](unsigned int position);
		~Array();
		unsigned int size() const;
};

#include "Array.tpp"

#endif