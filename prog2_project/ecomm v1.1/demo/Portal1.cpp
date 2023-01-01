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
    list<Product*>p;
    string myText;
    // Read from the text file
    ifstream readFile ("PlatformToPortal.txt");
    // Use a while loop together with the getline() function to read the file line by line
    vector<vector<string>>inputs;
    while (getline(readFile, myText)) {
        // Output the text from the file
        // string reqid;
        string a1 = ""; // this will be used for appending each char of a continuous string(continous string->string with no spaces)
        vector<string>a; // this is the vector<string>a that will contain the first string as name of the object and second one the number specified(if any like that of FlightSimple)
        for(int i=0;i<myText.size();i++)
        {
            if(myText[i]!=' '&& i!=(int)myText.size()-1)
            {
                a1+=myText[i];
            }
            else if(i!=(int)myText.size()-1 && myText[i]==' ') // if we encounter a space when iterating through a input then we add the a1 string to the vector of strings and reinitalizes the original string.
            {
                a.push_back(a1);
                a1 = "";
            }
            else if(i==(int)myText.size()-1) // if we are at the last index then we just that element to the a1 string and add the a1 string to the vector of strings.
            {
                a1+=myText[i];
                a.push_back(a1);
            }
        }
        inputs.push_back(a);
        for(auto it:this->reqid_sortod)
        {
            for(int i=0;i<inputs.size();i++)
            {
                if(stoi(inputs[i][1])==it.first)
                {
                        Product *p1 = new Product(inputs[i][3],inputs[i][2],stof(inputs[i][4]),stoi(inputs[i][5]));
                        p.push_back(p1);
                }
            }
            p.sort(ProductCompare(it.second));
            for(auto it:p)
            {
                cout<<it->getName()<<" ";// actual printing order to be seen;
            }
            cout<<endl;
            p.clear();
        }
    }

    readFile.close();
}


