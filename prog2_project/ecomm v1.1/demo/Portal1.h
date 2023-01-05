# include <bits/stdc++.h>
# include "../ecomm/Portal.h"
# include "../ecomm/Product.h"

# ifndef PORTAL1_H
# define PORTAL1_H
using namespace std;

class ProductCompare{
    private:
        string comparator;
        const string price ="Price";
        const string name = "Name";
    public:
        ProductCompare(string myText)
        {
            this->comparator = myText;
        }
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

class Portal1:public Portal{
    public:
        Portal1(string id);
        void processUserCommand(string command);
        void Response();
};

#endif
