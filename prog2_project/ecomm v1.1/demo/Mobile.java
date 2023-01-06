package demo;
// import java.util.*;
import ecomm.Globals;

// child class of product with some extra functionality
public class Mobile extends ecomm.Product{
    //data members
    private Globals.Category cat;
    private String name;
    private String id;  // product id will contain the Seller id plus it's name.
    private float price;
    private int quantity;
    
    //ctor
    public Mobile(String name,String id,float price, int quantity)
    {
        this.cat = Globals.Category.Mobile;
        this.name = name;
        this.id = id;
        this.price = price;
        this.quantity = quantity;
    }

    //getters
    public Globals.Category getCategory()
    {
        return this.cat;
    }
	public  String getName()
    {
        return this.name;
    }
	public  String getProductID()
    {
        return this.id;
    }
	public float getPrice()
    {
        return this.price;
    }
	public int getQuantity()
    {
        return this.quantity;
    }

    //extra methods
    //decrease quantity by a certain amount, indicating that a buy was made
    public void setQuantity(int dec)
    {
        this.quantity-=dec;
    }
    //for printing records when portal check is called
	public String toString(){
		return this.getName()+" "+this.getProductID()+" "+this.getPrice()+" "+this.getQuantity();
	}
    
}