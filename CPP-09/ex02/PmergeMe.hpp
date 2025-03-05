#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <iomanip>
#include <ctime>

class PmergeMe{

    private:
        std::vector<int> vec;
        std::deque<int> deq;
        void mergeVector(int left, int right);
        void mergeDeque(int left, int right);
        void printDeque(std::deque<int> deq);
        void printVector(std::vector<int> vec);


    public: 
        PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
        void start(std::vector<int> vec);
};

#endif