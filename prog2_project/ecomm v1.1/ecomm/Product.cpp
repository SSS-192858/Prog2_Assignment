# include <bits/stdc++.h>
using namespace std;
# include "Product.h"

Product::Product(string cat, string name,float price, int quantity){
        this->category = cat;
        this->name = name;
        this->price = price;
        this-> quantity = quantity;
}
string Product::getCategory(){
        return this->category;
}
string Product:: getName(){
        return this->name;
}
	// string getProductID();
float Product:: getPrice(){
        return this->price;
}

int Product:: getQuantity(){
        return this->quantity;
}