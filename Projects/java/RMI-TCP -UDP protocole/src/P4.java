import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class P4 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//recive data from P1
		DatagramSocket serveur =new DatagramSocket(2006);
		byte [] senddata =new byte[10];
		byte [] recivedata =new byte[10];

		DatagramPacket recive =new DatagramPacket(recivedata, recivedata.length);
		serveur.receive(recive);
        String s= new String (recive.getData());
        s=s.trim();
        
        System.out.println("m="+Integer.parseInt(s)*2);
     
        
        /* retoure
        //info 
        int port =recive.getPort();
        InetAddress adr=recive.getAddress();
        
    	//send to P3
        String msg="message from p4";
		senddata=msg.getBytes();
        DatagramPacket sendP =new DatagramPacket(senddata, senddata.length,adr,port);
        serveur.send(sendP);
	*/
	
	}
}
