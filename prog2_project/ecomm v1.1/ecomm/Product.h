#include<bits/stdc++.h>

using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
    private:
    string category, name, productId;
    float price;
    int quantity;

    public:
    Product(string cat, string name, string productId, float price, int quantity);
    string getCategory();
	string getName();
	string getProductID();
	float getPrice();
	int getQuantity();
	void setQuantity(int decrease);
};

#endif