# include <bits/stdc++.h>
# include "ecomm/Portal.h"
# ifndef PORTAL1_H
# define PORTAL1_H
using namespace std;
class Portal1:public Portal{
    public:
        Portal1(string id);
        void processUserCommand(string command);
        void Response();
                
};
#endif