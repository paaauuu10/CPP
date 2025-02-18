/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:50 by pbotargu          #+#    #+#             */
/*   Updated: 2025/02/18 11:13:35 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>

template <typename T>
int easyfind(T const &container, int val)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), val);
    
    if (it == container.end())
        throw std::out_of_range("Value not found");

    return std::distance(container.begin(), it);
}
#endif