package demo;
// import java.util.*;
import ecomm.Globals;

public class Mobile extends ecomm.Product{

    private Globals.Category cat;
    private String name;
    private String id;
    private float price;
    private int quantity;
    // product id will contain the Seller id plus it's name.

    public Mobile(String name,String id,float price, int quantity)
    {
        this.cat = Globals.Category.Mobile;
        this.name = name;
        this.id = id;
        this.price = price;
        this.quantity = quantity;
    }
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
    public void setQuantity(int dec)
    {
        this.quantity-=dec;
    }
    
}