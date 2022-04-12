#pragma once

#include "Shape.hpp"

 class Circle final : public Shape
{
    using Shape::Shape;
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle() = delete;
    Circle(Circle&& circle) noexcept = default;
    ~Circle() noexcept override = default;

     Circle& operator=(Circle&& other) noexcept = default;
     Circle& operator=(const Circle& other) noexcept = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    [[deprecated]]
    double  getPi() ;
    void print() const override ;
private:
    double r_ = 0;
};
