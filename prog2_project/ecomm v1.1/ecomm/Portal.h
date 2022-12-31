# include <bits/stdc++.h>
using namespace std;
#ifndef PORTAL_H
#define PORTAL_H
class Portal{
    protected:
        map<int,string> reqid_sortod;
        static int Req_Id;
    public:
        virtual void processUserCommand(string command) = 0;
        virtual void Response()=0;
};

#endif