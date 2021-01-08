#pragma once
#include <vector>
#include <iostream>
#include <string>

class CartItem
{
private:
    std::string description, orderDate, deliveryDate;
    double cost;

public:
    void setCost(double c)
    {
        cost = c;
    }

    double getCost()
    {
        return cost;
    }
};

class Customer
{
private:
    std::string name, address;
};


class Payment
{

public:
    virtual ~Payment() = default;
    virtual void pay(double amount) {}

};
class ShoppingStrategy
{
    //Payment paymentMethod; // composition
private: std::vector<CartItem> listItems;

       double getTotalCost()
       {
           double total = 0.0;
           for (CartItem item : listItems)
           {
               total += item.getCost();
           }
           return total;
       }
public:
    void addItem(CartItem& item)
    {
        listItems.push_back(item);
    }
    void checkout(Payment& p)
    {
        p.pay(this->getTotalCost()); // strategy
    }
};
