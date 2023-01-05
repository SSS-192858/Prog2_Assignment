#include <bits/stdc++.h>
#include "Portal1.h"
using namespace std;

Portal1::Portal1(string id): Portal(id){}

void Portal1::processUserCommand(string command){
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

void Portal1::Response(){
    list<Product*>p;
    string myText;
    // Read from the text file
    ifstream readFile ("./demo/PlatformToPortal.txt");
    // Use a while loop together with the getline() function to read the file line by line
    vector<vector<string>>inputs;
    vector<vector<string>> inputs1;
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
        inputs1.push_back(a);
    }
    readFile.close();
    ofstream myFile;
    myFile.open("./demo/PlatformToPortal.txt");
    for (int i=0; i<inputs1.size(); i++){
        vector<string> temp = inputs1[i];
        if (temp[0] == this->PortalID){
            inputs.push_back(temp);
        }else{
            string st = "";
            for (int j=0; j<temp.size(); j++){
                st+=temp[j];
                st+=" ";
            }
            myFile << st <<"\n";
        } 
    }
    myFile.close();

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

    for (int i=0; i<requestsCompleted.size(); i++){
        this->reqid_sortod.erase(requestsCompleted[i]);
    }
}