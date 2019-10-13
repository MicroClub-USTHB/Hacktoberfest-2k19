import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class P1 {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scc=new Scanner(System.in);
		String n;
		System.out.println("Donnée la valeur de N svp: ");
		n=scc.next(); 
		
		
		
		try {
			Registry reg1=LocateRegistry.getRegistry("127.0.0.1",2004);
			
				RMI IP=(RMI) reg1.lookup("SD");
				IP.Data(Integer.parseInt(n));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		
		
		
		
		
	}

}
