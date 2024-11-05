/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:40:26 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/05 15:30:58 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() 
{
    Animal* ArrayDogsCats[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            ArrayDogsCats[i] = new Cat;
        else
            ArrayDogsCats[i] = new Dog;
        std::cout << std::endl;
    }

    for (int j = 0; j < 10; j++)
    {
        delete ArrayDogsCats[j];
        std::cout << std::endl;
    }
    
    const Animal* j = new Dog(); 
    const Animal* i = new Cat();
    delete j;//should not create a leak 
    delete i;
    
    return (0); 
}