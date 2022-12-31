# include <bits/stdc++.h>
# include "Product.h"
using namespace std;

Product::Product(string cat, string name, string productId, float price, int quantity){
    this->category = cat;
    this->name = name;
    this-> productId = productId;
    this->price = price;
    this-> quantity = quantity;
}

string Product::getCategory(){return this->category;}

string Product::getName(){return this->name;}

string Product::getProductID(){return this->productId;}

float Product::getPrice(){return this->price;}

int Product::getQuantity(){return this->quantity;}

void Product::setQuantity(int decrease){this->quantity = this->quantity - decrease;}