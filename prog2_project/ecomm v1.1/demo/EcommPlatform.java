package demo;

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
		File file = new File("PortalToPlatform.txt");
		
		try{
			Scanner sc = new Scanner(file);
			sc.close();
		}catch (IOException e){
			e.printStackTrace();
		}
		
	}

}
