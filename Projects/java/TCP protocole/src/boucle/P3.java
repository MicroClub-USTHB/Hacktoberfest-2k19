package boucle;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class P3 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		
		
			DatagramSocket serveur =new DatagramSocket(2005);
		
			while(true){
			byte [] senddata =new byte[10];
			byte [] recivedata =new byte[10];

			DatagramPacket recive =new DatagramPacket(recivedata, recivedata.length);
				
					serveur.receive(recive);
			        String s= new String (recive.getData());
			        InetAddress ipadd=recive.getAddress();
			        int port =recive.getPort();
			        System.err.println(s);
			        
			}
	}

}
