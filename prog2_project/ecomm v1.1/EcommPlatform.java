import java.util.*;
import java.io.*;
import ecomm.*;

public class EcommPlatform extends Platform {
	//list of sellers
	ArrayList<Seller> listSellers = new ArrayList<Seller>();

	//adding a seller to list
	@Override
	public boolean addSeller(Seller aSeller) {
		listSellers.add(aSeller);
		return true;
	}

	//will process the queries coming in from the PortalToPlatform.txt file and write them to PlatformToPortal.txt
	@Override
	public void processRequests(){
		//read method explained below
		List<String> queries = read();

		//now we iterate through the list of strings received from the read method,
		//and based on the request, write the result to PlatformToPortal.txt
		for (int i=0; i<queries.size(); i++){
			//splitting the queries and checking the first word of each
			String[] query = queries.get(i).split(" ");

			//if it is List, we need to print all Books/Mobiles, sorting taken care of in portal
			if (query[2].equals("List")){

				ArrayList<Product> result = new ArrayList<Product>();
				//adding all books/mobiles to an array list and using that array list to write to the file PlatformToPortal.txt
				if (query[3].equals("Book")){
					
					for (int j=0; j<listSellers.size(); j++){
						ArrayList<Product> temp = listSellers.get(j).findProducts(Globals.Category.Book);
						result.addAll(temp);
					}

				}else if (query[3].equals("Mobile")){

					for (int j=0; j<listSellers.size(); j++){
						ArrayList<Product> temp = listSellers.get(j).findProducts(Globals.Category.Mobile);
						result.addAll(temp);
					}
				}
				//method explained below
				writeListToFile(result, query[0], query[1]);

			}
			//if it is buy, we simply write portal id, request id, and transaction result
			else if(query[2].equals("Buy"))
			{
				String [] id = query[3].split("-");
				
				for(int j=0;j<listSellers.size();j++)
				{	
					//iterating through all products of sellers and checking which product id matches
					if(this.listSellers.get(j).getID().equals(id[0]))
					{
						// User wants to buy specified quantity of productID
						// Return true if transaction succeeds, false otherwise. 
						// Transaction fails if incorrect productID or quantity exceeds available inventory
						if(this.listSellers.get(j).buyProduct(query[3],Integer.parseInt(query[4])))
						{
							//method explained below
							writeForBack(query[0],query[1],"Success");
						}
						else
						{
							writeForBack(query[0],query[1],"Failure");
							
						}
						break;
					}
				}	
			}
			// if it is start we simply have to write <PortalID> <RequestID> category1 category2 ... 
			// (where categories are as in Globals getCategoryName()
			// which is what is done in writeStart method
			else
			{
				writeStart(query[0], query[1]);
			}
		}
	}

	//reads the PortalToPlatform.txt line by line and add those strings to a list and returns the list 
	public static List<String> read() {
		File file = new File("./demo/PortalToPlatform.txt");

		try {
			Scanner sc = new Scanner(file);
			List<String> query = new ArrayList<String>();

			while (sc.hasNextLine()) {
				String temp = sc.nextLine();
				query.add(temp);
			}
			sc.close();
			return query;

		} catch (FileNotFoundException e) {
			e.printStackTrace();
			List<String> temp = new ArrayList<String>();
			return temp;
		}
	}

	// writes sorted list to PlatformToPortal.txt
	public static void writeListToFile(ArrayList<Product> order, String portalId, String requestId){
		File file = new File("./demo/PlatformToPortal.txt");
		try{
			//if file doesn't exist, create it
			if (file.exists() == false){
				file.createNewFile();
			}
			PrintWriter print = new PrintWriter(new FileWriter(file, true));
			// writing to the file using to string method of product
			// aslo adding request and portal id
			for (int i=0; i<order.size(); i++){
				print.append(portalId+" "+requestId+" "+order.get(i).toString()+"\n");
			}
			print.close();

		}catch (IOException e){
			e.printStackTrace();
		}
	}

	//function called during buy commands
	public static void writeForBack(String PortalID,String ResponseID,String Result)
	{
		File file = new File("./demo/PlatformToPortal.txt");
		try{
			if (file.exists() == false){
				file.createNewFile();
			}
			PrintWriter print = new PrintWriter(new FileWriter(file, true));
			//we write the result as is to the file, with no changes
			print.append(PortalID+" "+ResponseID+" "+Result+"\n");
			print.close();

		}catch (IOException e){
			e.printStackTrace();
		}
	}
	
	//called for start commands
	public static void writeStart(String portalId, String requestId){
		File file = new File("./demo/PlatformToPortal.txt");
		try{
			if (file.exists() == false){
				file.createNewFile();
			}
			
			PrintWriter print = new PrintWriter(new FileWriter(file, true));

			//start commands have a fixed response, to list out all the categories available
			Globals temp = new Globals();
			
			//for that we create a temp object and obtain the category string from it
			print.append(portalId+" "+requestId+" "+temp.getCategoryName(Globals.Category.Book)+" "+temp.getCategoryName(Globals.Category.Mobile)+"\n");
			print.close();
		}catch (IOException e){
			e.printStackTrace();
		}
	}
}
