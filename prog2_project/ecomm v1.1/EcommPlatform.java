import java.util.*;
import java.io.*;
import ecomm.*;

public class EcommPlatform extends Platform {

	ArrayList<Seller> listSellers = new ArrayList<Seller>();

	
	@Override
	public boolean addSeller(Seller aSeller) {
		listSellers.add(aSeller);
		return true;
	}

	@Override
	public void processRequests(){
		List<String> queries = read();

		for (int i=0; i<queries.size(); i++){
			String[] query = queries.get(i).split(" ");
			if (query[2].equals("List")){

				ArrayList<Product> result = new ArrayList<Product>();
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

				writeListToFile(result, query[0], query[1]);

			}
			else if(query[2].equals("Buy"))
			{
				String [] id = query[3].split("-");
				
				for(int j=0;j<listSellers.size();j++)
				{	
					// System.out.println(this.listSellers.get(j).getID());
					if(this.listSellers.get(j).getID().equals(id[0]))
					{
						// System.out.println("Hee");
						if(this.listSellers.get(j).buyProduct(query[3],Integer.parseInt(query[4])))
						{
							writeForBack(query[0],query[1],"Success");
						}
						else
						{
							writeForBack(query[0],query[1],"Failure");
							
						}
						break;
					}
				}	
				// System.out.println("Hi");
			}
			else
			{
				writeStart(query[0], query[1]);
			}
		}
	}

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

	public static void writeListToFile(ArrayList<Product> order, String portalId, String requestId){
		File file = new File("./demo/PlatformToPortal.txt");
		try{
			if (file.exists() == false){
				file.createNewFile();
			}
			PrintWriter print = new PrintWriter(new FileWriter(file, true));
			for (int i=0; i<order.size(); i++){
				print.append(portalId+" "+requestId+" "+order.get(i).toString()+"\n");
			}
			print.close();

		}catch (IOException e){
			e.printStackTrace();
		}
	}

	public static void writeForBack(String PortalID,String ResponseID,String Result)
	{
		File file = new File("./demo/PlatformToPortal.txt");
		try{
			if (file.exists() == false){
				file.createNewFile();
			}
			PrintWriter print = new PrintWriter(new FileWriter(file, true));
			print.append(PortalID+" "+ResponseID+" "+Result+"\n");
			print.close();

		}catch (IOException e){
			e.printStackTrace();
		}
	}
	
	public static void writeStart(String portalId, String requestId){
		File file = new File("./demo/PlatformToPortal.txt");
		try{
			if (file.exists() == false){
				file.createNewFile();
			}
			
			PrintWriter print = new PrintWriter(new FileWriter(file, true));

			Globals temp = new Globals();
			
			print.append(portalId+" "+requestId+" "+temp.getCategoryName(Globals.Category.Book)+" "+temp.getCategoryName(Globals.Category.Mobile)+"\n");
			print.close();
		}catch (IOException e){
			e.printStackTrace();
		}
	}
}
