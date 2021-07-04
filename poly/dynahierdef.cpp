#include "dynahier.hpp"
#include<iostream>

//def Circle
void Circle::draw() const{
    std::cout<<"Circle::draw"<<std::endl;
}

Coord Circle::center_of_gravity() const{
    std::cout<<"Circle::center"<<std::endl;
}

//def Line
void Line::draw() const{
    std::cout<<"Line::draw"<<std::endl;
}

Coord Line::center_of_gravity() const{
    std::cout<<"Line::center"<<std::endl;
}