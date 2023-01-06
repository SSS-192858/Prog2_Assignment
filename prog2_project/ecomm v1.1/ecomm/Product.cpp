# include <bits/stdc++.h>
using namespace std;
# include "Product.h"

//ctor
Product::Product(string cat, string name,float price, int quantity){
        this->category = cat;
        this->name = name;
        this->price = price;
        this-> quantity = quantity;
}
//getters
string Product::getCategory(){
        return this->category;
}
string Product:: getName(){
        return this->name;
}
float Product:: getPrice(){
        return this->price;
}
int Product:: getQuantity(){
        return this->quantity;
}