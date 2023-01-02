package demo.IMT2021028;

import ecomm.*;
import java.util.*;

public class IMT2021028_seller extends Seller{

    private ArrayList<Product> productsOffered;
    private ArrayList<Platform> platforms;

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
        boolean transactionStatus = false;
        int i1=0;
        for(int i=0;i<productsOffered.size();i++){
            if (productID == productsOffered.get(i).getProductID()){
                transactionStatus = true;
                i1=i;
                break;
            }
        }

        if (transactionStatus){
            if (quantity>productsOffered.get(i1).getQuantity()){
                transactionStatus = false;
            }else{
                transactionStatus = true;
                productsOffered.get(i1).setQuantity(quantity);
            }
        }
        return transactionStatus;
    };

    public void AddProd(Product obj){
		this.productsOffered.add(obj);
	}
}