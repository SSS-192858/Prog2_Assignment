// package demo;

// import java.util.Comparator;

// import ecomm.Product;

// public class ProdComparator implements Comparator<Product>{

//     private String param;
//     ProdComparator(String p)
//     {
//         this.param = p;
//     }
    
//     @Override
//     public int compare(Product a, Product b) {
//         if(this.param=="Price")
//         {
//             return Float.compare(a.getPrice(), b.getPrice());
//         }
//         else if(this.param=="Name")
//         {
//             return a.getName().compareTo(b.getName());
//         }
//         else
//         {
//             return 0;
//         }
//     }
    
// }
