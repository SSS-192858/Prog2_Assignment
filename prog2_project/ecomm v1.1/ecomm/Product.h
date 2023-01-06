#include<bits/stdc++.h>

using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H

//product class
class Product
{
    private:
    //data members
    string category, name; //productId;
    float price;
    int quantity;

    public:
    Product(string cat, string name,float price, int quantity);
    // common queries to get category, unique name, price, and number available
    string getCategory();
	string getName();
	// string getProductID();
	float getPrice();
	int getQuantity();
};

#endif