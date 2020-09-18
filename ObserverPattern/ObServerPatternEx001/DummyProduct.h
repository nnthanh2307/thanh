#ifndef DUMMYPRODUCT_H
#define DUMMYPRODUCT_H
#pragma once
#include "ASubject.h"

class DummyProduct : public ASubject
{
public:
    explicit DummyProduct();
public:
    void ChangePrice(float price);
};

#endif // DUMMYPRODUCT_H
