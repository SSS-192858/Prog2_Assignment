# include <bits/stdc++.h>
# include "../ecomm/Portal.h"
# include "../ecomm/Product.h"

# ifndef PORTAL1_H
# define PORTAL1_H
using namespace std;

// comparator to sort based on name or price
class ProductCompare{
    private:
        string comparator;
        const string price ="Price";
        const string name = "Name";
    public:
        //constructor and setting sorting parameter
        ProductCompare(string myText)
        {
            this->comparator = myText;
        }

        //operator overloading, this returns the comparison of 2 products for sorting based on sorting parameter
        bool operator()(Product * p1,Product *p2)
        {
          if(this->comparator==price)
          {
            return p1->getPrice() < p2->getPrice();
          } 
          else if(this->comparator==name)
          {
            return p1->getName() < p2->getName();
          }
          else
          {
            return 2;
          } 
        }
};

// child class of product with some extra functionality
class Portal1:public Portal{
    public:
        Portal1(string id);
        void processUserCommand(string command);
        void Response();
};

#endif
