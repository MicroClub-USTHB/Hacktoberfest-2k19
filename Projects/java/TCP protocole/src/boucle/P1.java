package boucle;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class P1 {

	public static void main(String []args){

		
		
			try {
				Socket c=new Socket("localhost",2004);
				System.out.println("holla.");
				ObjectOutputStream out=new ObjectOutputStream(c.getOutputStream());
				while(true){
					
				System.out.println("donner N:");
				Scanner sc=new Scanner(System.in);
				String n=sc.next();
				out.writeObject(n);
				
				ObjectInputStream in=new ObjectInputStream(c.getInputStream());
				String val=(String)in.readObject();
				System.err.println(val);
				}
				
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}

