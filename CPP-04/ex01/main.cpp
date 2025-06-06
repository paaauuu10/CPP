/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:40:26 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/06 11:47:20 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() 
{
    Animal* ArrayAnimals[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            ArrayAnimals[i] = new Cat;
        else
            ArrayAnimals[i] = new Dog;
        std::cout << std::endl;
    }

    for (int j = 0; j < 10; j++)
    {
        delete ArrayAnimals[j];
        std::cout << std::endl;
    }
    
    const Animal* j = new Dog(); 
    const Animal* i = new Cat();
    delete j; //should not create a leak 
    delete i;
    
    return (0); 
}