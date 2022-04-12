//
// Created by norbert on 12.04.2022.
//

#include <memory>
#include "Shape.hpp"

#ifndef MODERN_CPP_FACTORYMETHOD_H
#define MODERN_CPP_FACTORYMETHOD_H

#endif //MODERN_CPP_FACTORYMETHOD_H


template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args);