/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:50 by pbotargu          #+#    #+#             */
/*   Updated: 2025/02/13 17:15:51 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>

template <typename T>
int	easyfind(T const &container, int val)
{
    if (std::find(container.begin(), container.end(), val) == container.end())
        throw std::out_of_range("Value not found");
    
    typename T::const_iterator it;
    int pos;
    
    it = std::find(container.begin(), container.end(), val);
    pos = std::distance(container.begin(), it);
    return pos;
}
#endif