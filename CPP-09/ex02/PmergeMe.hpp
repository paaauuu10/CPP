#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <cstring>
# include <sstream>
# include <exception>
# include <algorithm>
# include <cstdlib>
# include <set>
# include <deque>
# include <vector>

class PmergeMe
{
    public:
        static void             parse(int argc, char **argv);
        static std::deque<int>  createDeque(int argc, char **argv);
        static std::vector<int>   createVector(int argc, char **argv);
        static void             start(std::deque<int> & deque, std::vector<int> & vec, int argc);
        static std::string      toString(int a_value);
    private:
        PmergeMe();
        ~PmergeMe();

        PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

        static bool         _isDigit(char *input);
        static bool         _isRepeated(char **argv);
        static bool         _isSorted(char **argv);
        static void         _mergeV(std::vector<int> & vec);
        static std::vector<int> _algorithmVector(std::vector<int> & vec);
        static void         _mergeD(std::deque<int> & deque);
        static std::deque<int>  _algorithmDeque(std::deque<int> & deque);
        static void         _printDeque(std::deque<int> & deque);
        static void         _printVector(std::vector<int> & vec);

        class InvalidInputException : public std::invalid_argument
        {
            public:
                InvalidInputException(std::string const & message);
        };
};

#endif