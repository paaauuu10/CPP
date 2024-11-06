/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:40:26 by pbotargu          #+#    #+#             */
/*   Updated: 2024/11/06 11:33:28 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() 
{
    const Animal* meta = new Animal();
    std::cout << std::endl;
    
    const Animal* j = new Dog();
    std::cout << std::endl;
    
    const Animal* i = new Cat();
    std::cout << std::endl;
    
    std::cout << j->getType() << ": "; 
    j->makeSound();
    std::cout << std::endl;
    
    std::cout << i->getType() << ": "; 
    i->makeSound();
    std::cout << std::endl;
    
    std::cout << meta->getType() << ": ";
    meta->makeSound();
    std::cout << std::endl;
    
    delete meta;
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;
    
    delete i;
    std::cout << std::endl;
   
    const WrongAnimal* wAnimal = new WrongAnimal();
    std::cout << std::endl;
    
    const WrongAnimal* wCat = new WrongCat();
    std::cout << std::endl;

    const WrongCat *cat = new WrongCat();
    std::cout << std::endl;
    
    std::cout << wAnimal->getType() << ": "; 
    wAnimal->makeSound();
    std::cout << std::endl;
    
    std::cout << wCat->getType() << ": "; 
    wCat->makeSound();
    std::cout << std::endl;

    std::cout << cat->getType() << ": "; 
    cat->makeSound();
    std::cout << std::endl;

    delete wAnimal;
    std::cout << std::endl;
    
    delete wCat;
    std::cout << std::endl;

    delete cat;
    std::cout << std::endl;
    
    return (0); 
}