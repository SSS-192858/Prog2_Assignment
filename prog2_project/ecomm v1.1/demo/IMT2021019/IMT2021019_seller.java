package demo.IMT2021019;

import java.util.*;
import ecomm.*;

public class IMT2021019_seller extends Seller{

    private String sellername;
    private ArrayList<Product> productsOffered;
    private ArrayList<Platform> platforms;

    public IMT2021019_seller(String id){
        super(id);
        this.sellername = "Siddharth";
    }
	
	// Platform it is being added to.
	// Should in turn add itself to the Platform (with addSeller)
	public void addPlatform(Platform thePlatform){
        platforms.add(thePlatform);
        thePlatform.addSeller(this);
    };
	
	// Seller to return listing of Products of specified Category
	public ArrayList<Product> findProducts(Globals.Category whichOne){
        ArrayList<Product> temp = new ArrayList<Product>();

        for (int i=0; i<productsOffered.size(); i++){
            if (productsOffered.get(i).getCategory().equals(whichOne)){
                temp.add(this.productsOffered.get(i));
            }
        }

        return temp;
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
