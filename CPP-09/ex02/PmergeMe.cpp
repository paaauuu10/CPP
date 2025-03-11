#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {return ;}

PmergeMe::~PmergeMe() {return ;}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
        return (*this);
	return (*this);
}

bool    PmergeMe::_isDigit(char *input)
{
    int i = 0;

    while (input[i])
    {
        if (!isdigit(input[i]))
            return (true);
        ++i;
    }
    return (false);
}

bool    PmergeMe::_isRepeated(char **argv)
{
    std::set<int>   seenNumbers;

    for (int i = 1; argv[i]; ++i)
    {
        if (seenNumbers.find(atoi(argv[i])) != seenNumbers.end())
            return (true);
        seenNumbers.insert(atoi(argv[i]));
    }

    return (false);
}

bool    PmergeMe::_isSorted(char **argv)
{
    for (int i = 1; argv[i + 1]; ++i)
    {
        if (atoi(argv[i]) > atoi(argv[i + 1]))
            return (false);
    }
    return (true);
}

void PmergeMe::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        if (_isDigit(argv[i]))
            throw (std::invalid_argument("Error: there are NO numbers characters"));
    }

    if (_isRepeated(argv))
        throw (std::invalid_argument("Error: You have a number repited"));
    if (_isSorted(argv))
        throw (std::invalid_argument("Ups! You're trying to order a list that it's already ordered!"));
}

std::deque<int> PmergeMe::createDeque(int argc, char **argv)
{
    std::deque<int> deque;

    std::transform(argv + 1, argv + argc, std::back_inserter(deque), &atoi);
    return (deque);
}

std::vector<int> PmergeMe::createVector(int argc, char **argv)
{
    std::vector<int> vec;
    std::transform(argv + 1, argv + argc, std::back_inserter(vec), &atoi);
    return vec;
}

void PmergeMe::start(std::deque<int> &deque, std::vector<int> &vec, int argc)
{
    clock_t    dequeTime[2];
    clock_t    vectorTime[2];

    std::cout << "Before deque: " << std::endl;
    _printDeque(deque);
    std::cout << std::endl;
    dequeTime[0] = clock();
    _mergeD(deque);
    dequeTime[1] = clock();
    std::cout << "After algorithm deque: " << std::endl;
    _printDeque(deque);
    std::cout << std::endl;


    std::cout << "Before vec: " << std::endl;
    _printVector(vec);
    std::cout << std::endl;
    vectorTime[0] = clock();
    _mergeV(vec);
    vectorTime[1] = clock();
    std::cout << "After algorithm vec: " << std::endl;
    _printVector(vec);
    std::cout << std::endl;

    double timeDeque = (static_cast<double>(dequeTime[1] - dequeTime[0]) / CLOCKS_PER_SEC) * 1000000;
    double timeVector = (static_cast<double>(vectorTime[1] - vectorTime[0]) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << timeDeque << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << timeVector << " us" << std::endl;
}


void PmergeMe::_mergeV(std::vector<int> & vec)
{
    vec = _algorithmVector(vec);
}

std::string PmergeMe::toString(int a_value)
{
    std::ostringstream out;
    out << a_value;
    return out.str();
}

std::vector<int> PmergeMe::_algorithmVector(std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return (vec) ;

    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> sorted;

    size_t i = 0;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (i < vec.size() / 2)
            left.push_back(*it);
        else
            right.push_back(*it);
        ++i;
    }

    left = _algorithmVector(left);
    right = _algorithmVector(right);

    while (!left.empty() && !right.empty())
    {
        if (left.front() < right.front())
        {
            sorted.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            sorted.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
    {
        sorted.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty())
    {
        sorted.push_back(right.front());
        right.erase(right.begin());
    }

    return (sorted);
}

void    PmergeMe::_mergeD(std::deque<int> & deque)
{
    deque = _algorithmDeque(deque);
}

std::deque<int> PmergeMe::_algorithmDeque(std::deque<int> & deque)
{
    if (deque.size() <= 1)
        return (deque);

    std::deque<int> left;
    std::deque<int> right;
    std::deque<int> sorted;

    size_t i = 0;
    for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); ++it)
    {
        if (i < deque.size() / 2)
            left.push_back(*it);
        else
            right.push_back(*it);
        ++i;
    }

    left = _algorithmDeque(left);
    right = _algorithmDeque(right);

    while (!left.empty() && !right.empty())
    {
        if (left.front() < right.front())
        {
            sorted.push_back(left.front());
            left.pop_front();
        }
        else
        {
            sorted.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty())
    {
        sorted.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty())
    {
        sorted.push_back(right.front());
        right.pop_front();
    }

    return (sorted);
}

void PmergeMe::_printDeque(std::deque<int> &deq){
    for (size_t i = 0; i < deq.size(); i++){
        if (deq.size() < 6)
            std::cout << " " << deq[i];
        else if (i < 4)
            std::cout << " " << deq[i];
        else if (i > 3){
            std::cout << " [...]";
            break ;
        }
    }
    std::cout << std::endl;
}

void PmergeMe::_printVector(std::vector<int> &vec){
    for (size_t i = 0; i < vec.size(); i++){
        if (vec.size() < 6)
            std::cout << " " << vec[i];
        else if (i < 4)
            std::cout << " " << vec[i];
        else if (i > 3){
            std::cout << " [...]";
            break ;
        }
    }
    std::cout << std::endl;
}


PmergeMe::InvalidInputException::InvalidInputException(std::string const & message) \
    : std::invalid_argument(message) {return ;}
