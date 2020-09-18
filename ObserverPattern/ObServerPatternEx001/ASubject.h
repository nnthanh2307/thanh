#ifndef ASUBJECT_H
#define ASUBJECT_H
//Header File
#pragma once
#include <vector>
#include <list>
#include "shop.h"


class ASubject
{
public:
    //Lets keep a track of all the shops we have observing
    std::vector<Shop*> list;

public:
    void Attach(Shop *product);
    void Detach(Shop *product);
    void Notify(float price);
};

#endif // ASUBJECT_H
