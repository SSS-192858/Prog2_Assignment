package demo.IMT2021058;

import java.util.ArrayList;
import ecomm.*;
import demo.*;
public class IMT2021058_seller extends Seller {
	// Array lists storing the products offered by the seller, and the platforms he sells them on
    private ArrayList<Product> Prod_Offrs = new ArrayList<Product>();
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
					// we will downcast because parent class product did not have a method to
                    // decrease the quantoty, hence we downcast the product, set quantity after selling
                    // and again add it at the original index in the array list
					if(this.Prod_Offrs.get(i).getCategory()==Globals.Category.Book)
					{
						Book b1 = (Book)this.Prod_Offrs.get(i);
						b1.setQuantity(quantity);
						this.Prod_Offrs.add(i,b1);
					}
					else
					{
						Mobile m1 = (Mobile)this.Prod_Offrs.get(i);
						m1.setQuantity(quantity);
						this.Prod_Offrs.add(i,m1);
					}
					return true;
				}else{
					return false;
				}
			}
		}
		return false;
	}
	//add product to the list of products offered
	public void AddProd(Product obj)
	{
		this.Prod_Offrs.add(obj);
	}	

}

