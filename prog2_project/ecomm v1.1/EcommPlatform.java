import java.util.*;
import java.io.*;
import ecomm.Platform;
import ecomm.Seller;

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
			
		}
	}

	public static List<String> read(){
		File file = new File("./demo/PortalToPlatform.txt");
		
		try {
			Scanner sc = new Scanner(file);
			List<String> query = new ArrayList<String>();

			while (sc.hasNextLine()){
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
}
