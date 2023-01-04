#include<bits/stdc++.h>

using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
    private:
    string category, name; //productId;
    float price;
    int quantity;

    public:
    Product(string cat, string name,float price, int quantity){
        this->category = cat;
        this->name = name;
        this->price = price;
        this-> quantity = quantity;
    }

    string getCategory(){
        return this->category;
    }
	string getName(){
        return this->name;
    }
	// string getProductID();
	float getPrice(){
        return this->price;
    }

	int getQuantity(){
        return this->quantity;
    }
};

#endif