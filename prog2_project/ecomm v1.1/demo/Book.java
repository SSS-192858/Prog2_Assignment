package demo;
import ecomm.*;
import ecomm.Globals;

// child class of product with some extra functionality
public class Book extends Product{
    //data members
    private Globals.Category category;
    private String name;
    private String productId;   //sellerName-productName
    private float price;
    private int quantity;

    //ctor
    public Book(String name, String productId, float price, int quantity){

        this.category = Globals.Category.Book;
        this.name = name;
        this.productId = productId;
        this.price = price;
        this.quantity = quantity;
    }

    //getters
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

    //extra methods
    //decrease quantity by a certain amount, indicating that a buy was made
    public void setQuantity(int decrease){
        this.quantity = this.quantity - decrease;
    }
    //for printing records when portal check is called
	public String toString(){
		return this.getName()+" "+this.getProductID()+" "+this.getPrice()+" "+this.getQuantity();
	}
    
}
