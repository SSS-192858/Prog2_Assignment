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
        Portal1(string id):Portal(id){}

        void processUserCommand(string command)
        {
            ofstream fwrite;
            fwrite.open("./demo/PortalToPlatform.txt",ios::app);
            if(command[0]=='L'){
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
                sortorder.erase(0,1);
                this->reqid_sortod[this->Req_Id] = sortorder; 
                fwrite << this->PortalID<<" "<<this->Req_Id<<" "<<command;
                
            }
            else
            {
                fwrite << this->PortalID<<" "<<this->Req_Id<<" "<<command;
            }
            this->Req_Id++;
            // check for the SortOrder.
            fwrite <<"\n";
            fwrite.close();
        }

        void Response()
        {
            list<Product*>p;
            string myText;
            // Read from the text file
            ifstream readFile ("./demo/PlatformToPortal.txt");
            // Use a while loop together with the getline() function to read the file line by line
            vector<vector<string>>inputs;
            vector<int> requestsCompleted;
            // cout<<"Initialisations done"<<endl;

            while (getline(readFile, myText)) {
                // Output the text from the file
                // string reqid;
                // cout<<myText<<endl;
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
            }

            int minReqId = stoi(inputs[0][1]);
            int maxReqId = stoi(inputs[inputs.size()-1][1]);

            for (int it=minReqId; it<=maxReqId; it++){
                if (this->reqid_sortod.find(it) != this->reqid_sortod.end()){
                    for(int i=0;i<inputs.size();i++)
                    {
                        // cout<<stoi(inputs[i][1])<<" "<<it.first<<endl;
                        if(stoi(inputs[i][1])==it)
                        {
                            Product *p1 = new Product(inputs[i][3],inputs[i][2],stof(inputs[i][4]),stoi(inputs[i][5]));
                            p.push_back(p1);
                        }
                    }
                    p.sort(ProductCompare(this->reqid_sortod[it]));
                

                    for(auto it1:p)
                    {
                        cout<<this->PortalID<<" "<<it<<" "<<it1->getName()<<" "<<it1->getCategory()<<" "<<it1->getPrice()<<" "<<it1->getQuantity()<<endl;
                    }
                    p.clear();
                    requestsCompleted.push_back(it);

                }else{
                    for (int i=0; i<inputs.size(); i++){
                        if (it == stoi(inputs[i][1])){
                            for (int j=0; j<inputs[i].size(); j++){
                                cout<<inputs[i][j]<<" ";
                            }
                            cout<<endl;
                            break;
                        }
                    }
                }
            }

            readFile.close();

            ofstream fwrite;
            fwrite.open("./demo/PlatformToPortal.txt");
            fwrite <<"";
            fwrite.close();
            for (int i=0; i<requestsCompleted.size(); i++){
                this->reqid_sortod.erase(requestsCompleted[i]);
            }
        }
};

#endif
