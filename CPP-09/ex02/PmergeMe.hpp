#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe{

    private:
        std::vector<int> vec;
        std::deque<int> deq;
        void mergeVector(int left, int right);
        void printDeque(std::deque<int> deq);
        void printVector(std::vector<int> vec);


    public: 
   // void mergeVector(std::vector<int> &vec, int left, int right);
    void start(std::vector<int> vec);
};

#endif