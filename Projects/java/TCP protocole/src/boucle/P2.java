package boucle;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class P2 {

	public static void main(String []args){
		ServerSocket s;
		try {
			s = new ServerSocket(2004);
			System.err.println("waiting c2 ...");
			Socket con = s.accept();
			ObjectInputStream in=new ObjectInputStream(con.getInputStream());
			
			while(true){
			
			System.err.println("connected..");
			
			
			String n= (String) in.readObject();	
			System.err.println(n); 
			
			ObjectOutputStream out=new ObjectOutputStream(con.getOutputStream());
			String m=Integer.toString(Integer.parseInt(n)*2);
			out.writeObject(m);
			
			DatagramSocket client =new DatagramSocket();
			InetAddress ipadd=InetAddress.getByName("localhost");
			byte [] senddata =new byte[10];
			byte [] recivedata =new byte[10];
			String phr ="MIL";
			senddata=phr.getBytes();
	        DatagramPacket sendP =new DatagramPacket(senddata, senddata.length,ipadd,2005);
	        client.send(sendP);
	        
			
			
			
			
			
			
			
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}
}
