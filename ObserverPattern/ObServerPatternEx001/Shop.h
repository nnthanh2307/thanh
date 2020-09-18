#ifndef SHOP_H
#define SHOP_H
//Header File
#pragma once
#include <iostream>
#include <string>
#include "IObserver.h"

class Shop : IObserver
{
public:
    Shop();
    //Name of the Shop
    std::string name;
    float price;
public:
    Shop(std::string n);
    void Update(float price);
};
#endif // SHOP_H
