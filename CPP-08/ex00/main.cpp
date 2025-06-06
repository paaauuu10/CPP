/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:52 by pbotargu          #+#    #+#             */
/*   Updated: 2025/02/13 17:15:53 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> vector;
	int				position;

	for (int i = 0; i < 5; i++)
        vector.push_back(i);
	try
	{
		for (int i = 0; i < 5; i++){
            position = easyfind(vector, i);
		    std::cout << "Position: " << position << std::endl;
        }
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		position = easyfind(vector, 5);
		std::cout << "Position: " << position << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
