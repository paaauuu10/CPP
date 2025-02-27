#include "PmergeMe.hpp"
void PmergeMe::printDeque(std::deque<int> deq){
    for (size_t i = 0; i < deq.size(); i++){
        if (deq.size() < 6)
            std::cout << " " << deq[i];
        else if (i < 5)
            std::cout << " " << deq[i];
        else if (i > 4){
            std::cout << " [...]";
            break ;
        }
    }
    std::cout << std::endl;
}

void PmergeMe::printVector(std::vector<int> vec){
    for (size_t i = 0; i < vec.size(); i++){
        if (vec.size() < 6)
            std::cout << " " << vec[i];
        else if (i < 5)
            std::cout << " " << vec[i];
        else if (i > 4){
            std::cout << " [...]";
            break ;
        }
    }
    std::cout << std::endl;
}

void PmergeMe::start(std::vector<int> tmp){
    std::vector<int>::iterator ite = tmp.end();
    for (std::vector<int>::iterator it = tmp.begin(); it != ite; it++){
        vec.push_back(*it);
        deq.push_back(*it);
    }
    std::cout << "Before: ";
    printVector(vec);
    std::cout << "After: ";
    std::clock_t startV = std::clock();
    mergeVector(0, vec.size());
    std::clock_t endV = std::clock();
    printVector(vec);
	double durationV = 100000 * (endV - startV) / CLOCKS_PER_SEC;
    //std::cout << "Time to process a range of " << vec.size() << " with std::vector : " << durationV << std::endl;
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << durationV << " us" 
              << std::endl;
    printDeque(deq);
}
void PmergeMe::mergeVector(int left, int right) {
    if (right - left <= 1) return; // Ya está ordenado si hay 1 elemento

    if (right - left == 2) { // Ordenar directamente 2 elementos
        if (vec[left] > vec[left + 1]) {
            std::swap(vec[left], vec[left + 1]);
        }
        return;
    }

    int mid = left + (right - left) / 2;
    mergeVector(left, mid);
    mergeVector(mid, right);

    std::vector<int> aux;
    aux.reserve(right - left);

    int i = left, j = mid;

    // Fusionar
    while (i < mid && j < right) {
        if (vec[i] < vec[j]) {
            aux.push_back(std::move(vec[i++]));
        } else {
            aux.push_back(std::move(vec[j++]));
        }
    }

    while (i < mid) aux.push_back(std::move(vec[i++]));
    while (j < right) aux.push_back(std::move(vec[j++]));

    std::move(aux.begin(), aux.end(), vec.begin() + left);
}
