#pragma once

#include "Color.hpp"

class Shape
{
public:
    Shape() = default;
    explicit Shape(Color c);
    virtual ~Shape() {}
    virtual double getArea() const = 0 ;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    Color getColor() const;
    void setColor(Color color);

private:
    Color color;
};
