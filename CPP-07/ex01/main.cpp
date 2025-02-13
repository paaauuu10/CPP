#include "iter.hpp"

static void lowerCase(char &c){
    if (c >= 'A' && c <= 'Z')
        c += 32;
}

static void incrementInt(int &n){
    n += 1;
}

/* STEP 1: SHOWING ORIGINAL ARRAYS
   STEP 2: ITERATING NOT THE FULL ARRAY
   STEP 3: SHOWING THE ITERATED ARRET
   STEP 4: ITERATING THE FULL ARRAY
   STEP 3 AGAIN!*/
   
int main(){
    char arr[] = {'A', 'B', 'C', 'D', 'F', 'G'};
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << std::endl << "Before ITER CHAR :" << std::endl << std::endl;
    for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << " ";
    iter(arr, 4, lowerCase);
    std::cout << std::endl << std::endl << "AFTER FIRTS ITERATION CHAR:" << std::endl << std::endl;
    for (size_t i = 0; i < 6; i++)
		std::cout << arr[i] << " ";
    iter(arr, 6, lowerCase);
    std::cout << std::endl << std::endl << "AFTER SECOND ITERATION CHAR:" << std::endl << std::endl;
    for (size_t i = 0; i < 6; i++)
            std::cout << arr[i] << " ";
    
    std::cout << std::endl << std::endl << "Before ITER INT:" << std::endl << std::endl;
    for (size_t i = 0; i < 10; i++)
        std::cout << arr1[i] << " ";
    iter(arr1, 5, incrementInt);
    std::cout << std::endl << std::endl << "AFTER FIRTS ITERATION INT:" << std::endl << std::endl;
    for (size_t i = 0; i < 10; i++)
		std::cout << arr1[i] << " ";
    iter(arr1, 10, incrementInt);
    std::cout << std::endl << std::endl << "AFTER SECOND ITERATION INT:" << std::endl << std::endl;
    for (size_t i = 0; i < 10; i++)
		std::cout << arr1[i] << " ";
}