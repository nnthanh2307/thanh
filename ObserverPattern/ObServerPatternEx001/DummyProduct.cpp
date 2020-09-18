#include "DummyProduct.h"

DummyProduct::DummyProduct()
{
}
void DummyProduct::ChangePrice(float price)
{
    Notify(price);
}
