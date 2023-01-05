package demo;
import ecomm.*;
import ecomm.Globals;

public class Book extends Product{
    private Globals.Category category;
    private String name;
    private String productId;
    private float price;
    private int quantity;

    public Book(String name, String productId, float price, int quantity){

        this.category = Globals.Category.Book;
        this.name = name;
        this.productId = productId;
        this.price = price;
        this.quantity = quantity;
    }

    public Globals.Category getCategory(){
        return this.category;
    }

	public String getName(){
        return this.name;
    }

	public String getProductID(){
        return this.productId;
    }

	public float getPrice(){
        return this.price;
    }

	public int getQuantity(){
        return this.quantity;
    }

    public void setQuantity(int decrease){
        this.quantity = this.quantity - decrease;
    }
    
	public String toString(){
		return this.getName()+" "+this.getProductID()+" "+this.getPrice()+" "+this.getQuantity();
	}
    
}
