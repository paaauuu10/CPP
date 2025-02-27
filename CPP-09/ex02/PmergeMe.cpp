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
    std::cout << std::endl << "Before:";
    printVector(vec);
    std::cout << "After:";
    std::clock_t startV = std::clock();
    mergeVector(0, vec.size());
    std::clock_t endV = std::clock();
    printVector(vec);
    double timeMsVc = static_cast<double>(endV - startV) /
                          CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(3) << timeMsVc << " us" 
              << std::endl;
    std::cout << std::endl;
    
    std::cout << "-------------------------------" << std::endl << std::endl; 

    std::cout << "Before:";
    printDeque(deq);
    std::cout << "After:";
    std::clock_t startD = std::clock();
    mergeDeque(0, deq.size());
    std::clock_t endD = std::clock();
    printDeque(deq);
    double timeMsDq = static_cast<double>(endD - startD) /
                          CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(3) << timeMsDq << " us" 
              << std::endl;
    std::cout << std::endl;
}

void PmergeMe::mergeDeque(int left, int right) {
    if (right - left <= 1) return; // Ya está ordenado si hay 1 elemento

    if (right - left == 2) { // Ordenar directamente 2 elementos
        if (deq[left] > deq[left + 1]) {
            std::swap(deq[left], deq[left + 1]);
        }
        return;
    }

    int mid = left + (right - left) / 2;
    mergeDeque(left, mid);
    mergeDeque(mid, right);

    std::deque<int> aux;

    int i = left, j = mid;

    // Fusionar
    while (i < mid && j < right) {
        if (deq[i] < deq[j]) {
            aux.push_back(deq[i++]);  // Copia el valor de deq[i] en lugar de moverlo
        } else {
            aux.push_back(deq[j++]);  // Copia el valor de deq[j] en lugar de moverlo
        }
    }

    while (i < mid) aux.push_back(deq[i++]);  // Copia el valor de deq[i]
    while (j < right) aux.push_back(deq[j++]);  // Copia el valor de deq[j]

    // Copia los elementos de aux a deq
    for (size_t k = 0; k < aux.size(); ++k) {
        deq[left + k] = aux[k];
    }
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
            aux.push_back(vec[i++]);  // Copia el valor de vec[i] en lugar de moverlo
        } else {
            aux.push_back(vec[j++]);  // Copia el valor de vec[j] en lugar de moverlo
        }
    }

    while (i < mid) aux.push_back(vec[i++]);  // Copia el valor de vec[i]
    while (j < right) aux.push_back(vec[j++]);  // Copia el valor de vec[j]

    // Copia los elementos de aux a vec
    std::copy(aux.begin(), aux.end(), vec.begin() + left); // std::copy es parte de C++98
}

