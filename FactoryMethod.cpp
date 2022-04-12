//
// Created by norbert on 12.04.2022.
//

#include "FactoryMethod.h"

template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    std::shared_ptr<Shape> result = std::make_shared<DerivedType>(
            new DerivedType(std::forward<Arguments>(args)...)
            );
    return  result;
}