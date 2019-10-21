import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class P3 {
	public static void main(String[] args) {
		String n = null,m;
			
		int trm=0;
				try {
					
					ServerSocket s =new ServerSocket(2005);
					
					System.err.println("waiting P4 ...");
					
					Socket con = s.accept();
					
					System.err.println("connected..");
					
					ObjectInputStream in=new ObjectInputStream(con.getInputStream());
					n= (String) in.readObject();	
				
					System.err.println("n="+n);
					
					
	
			
					
					DatagramSocket client =new DatagramSocket();
					InetAddress ipadd=InetAddress.getByName("localhost");
					byte [] senddata =new byte[10];
					byte [] recivedata =new byte[10];
					
					senddata=n.getBytes();
			        DatagramPacket sendP =new DatagramPacket(senddata, senddata.length,ipadd,2006);
			        client.send(sendP);
			        
			        
			     /*retoure   
			        /*Recive datar from p4 
			        DatagramPacket recivep =new DatagramPacket(recivedata, recivedata.length);
			        client.receive(recivep);
			        String s1= new String (recivep.getData());
			        System.err.println("P3 data from P4: "+s1);
			
			        
					//send to p2
					String sm ="Message bien recu"; 
					ObjectOutputStream out=new ObjectOutputStream(con.getOutputStream());
					out.writeObject(sm);
			*/
			        
				} catch (Exception e) {
					// TODO: handle exception
				}
				
				
				
	}

}
