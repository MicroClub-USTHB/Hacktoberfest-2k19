import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class p1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

ip2 IP;
		
try {
			Registry reg1=LocateRegistry.getRegistry("127.0.0.1",2004);
			
			System.out.println("donner a:");
			Scanner sc=new Scanner(System.in);
			int n=sc.nextInt();
			System.out.println("donner b:");
			int n2=sc.nextInt();
			try {
				IP=(ip2) reg1.lookup("SD");
				System.err.println(IP.add(n, n2));
				System.err.println(IP.mult(n, n2));
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
			
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		
		
	}

}
