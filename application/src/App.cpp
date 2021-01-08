#include "shopstrategy.h"

class PayPalPayment : public Payment
{
public:
    void pay(double amount)
    {
        std::cout << "PayPalPayment. Amount = " << amount;
    }
};

class CreditCardPayment : public Payment
{
public:
    void pay(double amount)
    {
        std::cout << "CreditCardPayment. Amount = " << amount;
    }
};

class UPIPayment : public Payment
{
public:
    void pay(double amount)
    {
        std::cout << "UPIPayment. Amount = " << amount;
    }
};

void Printi()
{ 
     std::cout << "Products available" << std::endl;
     std::cout << "Press 1 for soap(25) " << std::endl;
     std::cout << "Press 2 for shampoo(100) " << std::endl;
     std::cout << "Press 3 for conditoner(50) " << std::endl;
     std::cout << "Press 0 to checkout " << std::endl;
  
}
void Printp()
{
    std::cout << "select payment mode" << std::endl;
    std::cout << "press 1 for PayPal" << std::endl;
    std::cout << "press 2 for CreditCard" << std::endl;
    std::cout << "press 3 for UPI" << std::endl;
}


int main()
{
    CartItem soap;
    soap.setCost(25);

    CartItem shampoo;
    shampoo.setCost(100);

    CartItem conditioner;
    conditioner.setCost(50);

    ShoppingStrategy cart;

    Printi();
   

    for (int i = 0; ;)
    {
        int x;
        std::cout<< "select item ";
        std::cin >> x;
        if (1 == x)
            cart.addItem(soap);
        else if(2 == x)
            cart.addItem(shampoo);
        else if (3 == x)
            cart.addItem(conditioner);
        else if(0 == x)
            break;
        else
            std::cout << "no such item exist" << std::endl;
    }
    
    //Payment paypal = new PayPalPayment();
    Printp();

    int x;
    std::cout << "select item ";
    std::cin >> x;
    if (1 == x) {
        PayPalPayment p;
        cart.checkout(p);
    }
       
    else if (2 == x) {
        CreditCardPayment cd;
        cart.checkout(cd);
    }
        
    else if (3 == x) 
    {
        UPIPayment upi;
        cart.checkout(upi);
    }
        
    else
        std::cout << "no such mode exists" << std::endl;
    

    return 0;
}
