#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>> ;

void printCollectionElements(const Collection& collection)
{
    for(const auto & it : collection)
        if(it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for(const auto & it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr unsigned int recursiveFib(const unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return recursiveFib(n - 1) + recursiveFib(n - 2);
    }
}

int main()
{
    constexpr unsigned int fib45 = recursiveFib(40); //Dla n = 45 system wysyłał SIGTERMA podczas kompilacji,
                                                        // ale różnica jest i tak widoczna.
    std::cout<<"45-th element is: "<<fib45<<std::endl;
    Collection shapes = {make_shared<Circle>(2.0), make_shared<Circle>(3.0), nullptr,
                         make_shared<Circle>(4.0), make_shared<Rectangle>(10.0, 5.0),
                         make_shared<Square>(3.0), make_shared<Circle>(4.0),
                         make_shared<Rectangle>(Color::RED), make_shared<Rectangle>(Color::GREEN),
                         make_shared<Circle>(Color::BLUE)};
    printCollectionElements(shapes);
    shapes.push_back(make_shared<Circle>(5.0));
    shapes.push_back(make_shared<Rectangle>(3.0, 1.0));
    shapes.push_back(make_shared<Square>(2.0));

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](auto first, auto second) {
        if(first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());});

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, [] (auto s) {
        if(s)
            return (s->getPerimeter() > 20);
        return false;}, "perimeter bigger than 20");

    findFirstShapeMatchingPredicate(shapes, [x = 10](auto s) {
        if(s)
            return (s->getArea() < x);
        return false;}, "area less than 10");

    return 0;
}

