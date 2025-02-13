#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename F>
void    iter(T *adrs, size_t len, F function){
    if (!adrs)
        return ;
    for (size_t i = 0; i < len; i++)
        function(adrs[i]);
}

#endif