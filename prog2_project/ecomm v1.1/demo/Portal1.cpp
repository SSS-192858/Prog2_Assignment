# include <bits/stdc++.h>
using namespace std;
# include "Product.h"
# include "Portal1.h"
class ProductCompare{
    private:
        string comparator;
        const string price ="Price";
        const string name = "Name";
    public:
        ProductCompare(string s)
        {
            this->comparator = s;
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
        }

};
Portal1::Portal1()
{
}
void Portal1::processUserCommand(string command)
{
    ofstream fwrite;
    fwrite.open("PortalToPlatform.txt");
    string sortorder;
    int count = 0;
    bool flg = false;
    for(int i=0;i<command.size();i++)
    {
        if(command[i]==' '&&count!=1)
        {
            count++;
        }
       else if(count==1 && command[i]==' ')
        {
            flg = true;
        }
        if(flg)
        {
            sortorder+=command[i];
        }
    }
    size_t ind = command.find(sortorder);
    command.erase(ind);
    this->reqid_sortod[this->Req_Id++] = sortorder; 
    fwrite << command;
    // check for the SortOrder.
    fwrite <<"/n";
    fwrite.close();
}
void Portal1::Response()
{
    string myText;
    // Read from the text file
    ifstream readFile ("PlatformToPotal.txt");
    // Use a while loop together with the getline() function to read the file line by line
    while (getline (readFile, myText)) {
        // Output the text from the file
        string reqid;
        int count = 0;
        bool flg = false;
        for(int i=0;i<myText.size();i++)
        {
            if(myText[i]==' '&&count!=1)
            {
                count++;
                flg = true;
            }
            else if(count==1 && myText[i]==' ')
            {
                flg = false;
                break;
            }
            if(flg)
            {
                reqid+=myText[i];
            }
        }
        string sortoder;
        sortoder = this->reqid_sortod[stoi(reqid)];
        
    }
    readFile.close();
}


