#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Usage: " << "./PmergeMe" << " int int ..." << std::endl;
        return (1);
    }
    try
    {
        PmergeMe::parse(argc, argv);
        std::deque<int> deque = PmergeMe::createDeque(argc, argv);
        std::vector<int> vec = PmergeMe::createVector(argc, argv);

        PmergeMe::start(deque, vec, argc);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}