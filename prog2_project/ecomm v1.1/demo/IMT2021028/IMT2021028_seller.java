package demo.IMT2021028;

import ecomm.*;
import java.util.*;

public class IMT2021028_seller extends Seller{

    private ArrayList<Product> productsOffered = new ArrayList<Product>();
    private ArrayList<Platform> platforms = new ArrayList<Platform>();

    public IMT2021028_seller(String id){
        super(id);
    }

    public void addPlatform(Platform thePlatform){
        platforms.add(thePlatform);
        thePlatform.addSeller(this);
    };
	
	// Seller to return listing of Products of specified Category
	public ArrayList<Product> findProducts(Globals.Category whichOne){
        ArrayList<Product> t = new ArrayList<Product>();
        for(int i=0;i<productsOffered.size();i++){
            if (productsOffered.get(i).getCategory() == whichOne){
                t.add(productsOffered.get(i));
            }
        }
        return t;
    };

	// User wants to buy specified quantity of productID
	// Return true if transaction succeeds, false otherwise. 
	// Transaction fails if incorrect productID or quantity exceeds available inventory
	public boolean buyProduct(String productID, int quantity){
        for (int i=0; i<productsOffered.size(); i++){
            if (productsOffered.get(i).getProductID().equals(productID)){
                if (productsOffered.get(i).getQuantity() >= quantity){
                    productsOffered.get(i).setQuantity(quantity);
                    return true;
                }else{
                    return false;
                }   
            }
        }
        return false;
    };

    public void AddProd(Product obj){
		this.productsOffered.add(obj);
	}
}