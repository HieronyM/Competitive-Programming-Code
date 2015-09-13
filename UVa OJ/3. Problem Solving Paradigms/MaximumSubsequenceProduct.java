import java.math.BigInteger;
import java.util.*;
import java.io.*;
//import java.util.Scanner;
//import java.util.Vector;
//import java.util.ArrayList;


/**
 *
 * @author Hierony
 */
class Main 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        int a,b;
		ArrayList <BigInteger> Data = new ArrayList <BigInteger>();
        BigInteger prod[][] = new BigInteger[105][105];
        
         // TODO code application logic here
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNext())
        {
			BigInteger temp = scanner.nextBigInteger();
			
			if(!temp.equals(BigInteger.valueOf(-999999)))  
			{
				Data.add(temp);
            }
            
            if(temp.equals(BigInteger.valueOf(-999999)))
			{
				if(Data.size() == 1) 
				{
					System.out.println(Data.get(0));
					Data.clear();
				}
				
				else
				{
					BigInteger maxi = Data.get(0).multiply(Data.get(1));
					
					for(a = 0; a < (Data.size()-1); a++ )
					{
						for(b = a+1; b < Data.size(); b++)
						{
							// First 
							if(b == a + 1)
							{
								prod[a][b] = Data.get(a).multiply(Data.get(b));
								//System.out.println(prod[a][b]);
								
								// maxi < prod[a][b] -->
								if(maxi.compareTo(prod[a][b]) == -1) maxi = prod[a][b];
							}
							
							// !First
							else
							{
								prod[a][b] = Data.get(b).multiply(prod[a][b-1]);							
								//System.out.println(prod[a][b]);
								
								// maxi < prod[a][b] -->
								if(maxi.compareTo(prod[a][b]) == -1) maxi = prod[a][b];
							}
						}
					}
					
					// Print Hasil
					System.out.println(maxi.toString());
					
					// Bersihkan
					Data.clear();
				} 
        }
     }
   }
}
