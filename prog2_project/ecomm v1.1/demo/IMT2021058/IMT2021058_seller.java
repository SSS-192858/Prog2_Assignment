package demo.IMT2021058;

import java.util.ArrayList;
import ecomm.*;

public class IMT2021058_seller extends Seller {

    private ArrayList<Product> Prod_Offrs = new ArrayList<Product>();
	// private String sellername;
    private ArrayList<Platform> platfs = new ArrayList<Platform>();

	// id is passed in by the class that instantiates sub-type of seller
	public IMT2021058_seller(String id) 
    {
		super(id);	
	}
	
	// Platform it is being added to.
	// Should in turn add itself to the Platform (with addSeller)
	public void addPlatform(Platform thePlatform)
    {
        this.platfs.add(thePlatform);
		thePlatform.addSeller(this);
    }
	
	// Seller to return listing of Products of specified Category
	public ArrayList<Product> findProducts(Globals.Category whichOne)
    {
		ArrayList<Product> temp = new ArrayList<>();
		for(int i=0;i<this.Prod_Offrs.size();i++)
		{
			if(this.Prod_Offrs.get(i).getCategory()==whichOne)
			{
				temp.add(this.Prod_Offrs.get(i));
			}
		}
		return temp;

    }
	// User wants to buy specified quantity of productID
	// Return true if transaction succeeds, false otherwise. 
	// Transaction fails if incorrect productID or quantity exceeds available inventory
	public boolean buyProduct(String productID, int quantity)
    {
		// System.out.println("h");
		for(int i=0;i<this.Prod_Offrs.size();i++)
		{
			if(this.Prod_Offrs.get(i).getProductID().equals(productID)){ 
				if(this.Prod_Offrs.get(i).getQuantity()>=quantity)
				{
					this.Prod_Offrs.get(i).setQuantity(quantity);
					return true;
				}else{
					return false;
				}
			}
		}
		return false;
	}
	public void AddProd(Product obj)
	{
		this.Prod_Offrs.add(obj);
	}	

}

