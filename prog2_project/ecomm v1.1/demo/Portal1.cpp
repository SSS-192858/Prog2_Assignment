#include <bits/stdc++.h>
#include "Portal1.h"
using namespace std;

Portal1::Portal1(string id): Portal(id){}

//processing commands involves writing the command to the file PortalToPlatform.txt
void Portal1::processUserCommand(string command){
    ofstream fwrite;
    fwrite.open("./demo/PortalToPlatform.txt",ios::app);

    //if command is list, then we shouldn't write the sort order to the file, it should be maintained in portal
    if(command[0]=='L'){
        string sortorder;
        int count = 0;
        bool flg = false;
        //logic to separate the sortorder from the string
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
        //we find the sortorder from command string, remove it
        size_t ind = command.find(sortorder);
        command.erase(ind);

        //sortorder has an extra space according to our logic, we remove it
        sortorder.erase(0,1);

        //storing sortorder with request id in portal, and writing the rest of the command to the file, with portal and request id
        this->reqid_sortod[this->Req_Id] = sortorder; 
        fwrite << this->PortalID<<" "<<this->Req_Id<<" "<<command;
        
    }
    else
    {   
        //else write the command as is, with the portal and request id
        fwrite << this->PortalID<<" "<<this->Req_Id<<" "<<command;
    }
    //update request id
    this->Req_Id++;
    
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

    //inputs1 now contains every single command, which may be from different portals as well
    //hence we now filter out the useful commands
    ofstream myFile;
    myFile.open("./demo/PlatformToPortal.txt");
    for (int i=0; i<inputs1.size(); i++){
        vector<string> temp = inputs1[i];

        //if correct portalid, we push it to inputs vector
        if (temp[0] == this->PortalID){
            inputs.push_back(temp);
        }else{
            //else we write it back to file
            string st = "";
            for (int j=0; j<temp.size(); j++){
                st+=temp[j];
                st+=" ";
            }
            myFile << st <<"\n";
        } 
    }
    myFile.close();

    //inputs now contains the correct requests, with the correct portal ids

    //obtaining the max and min request ids to be processed
    int minReqId = stoi(inputs[0][1]);
    int maxReqId = stoi(inputs[inputs.size()-1][1]);

    for (int it=minReqId; it<=maxReqId; it++){
        //if a sort order is present for the request id, then it was a list command
        
        if (this->reqid_sortod.find(it) != this->reqid_sortod.end()){
            //for these commands we iterate over all the records, find the records with the correct request ids
            for(int i=0;i<inputs.size();i++)
            {
                // cout<<stoi(inputs[i][1])<<" "<<it.first<<endl;
                if(stoi(inputs[i][1])==it)
                {
                    //we then create product ojects out of them
                    Product *p1 = new Product(inputs[i][3],inputs[i][2],stof(inputs[i][4]),stoi(inputs[i][5]));
                    p.push_back(p1);
                }
            }
            //we now sort based on the sort parameter, and print 
            p.sort(ProductCompare(this->reqid_sortod[it]));
        

            for(auto it1:p)
            {
                cout<<this->PortalID<<" "<<it<<" "<<it1->getName()<<" "<<it1->getCategory()<<" "<<it1->getPrice()<<" "<<it1->getQuantity()<<endl;
            }
            p.clear();
            //requests completed is a temporary vector containing the request ids whose sort order is to be removed, as we have now processed them
            requestsCompleted.push_back(it);

        }else{
            //if it was not a list command, we can print it as is to the terminal
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

    //final logic to remove the requestsCompleted from the map 
    for (int i=0; i<requestsCompleted.size(); i++){
        this->reqid_sortod.erase(requestsCompleted[i]);
    }
}