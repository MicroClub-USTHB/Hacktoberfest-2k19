import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class P2  extends java.rmi.server.UnicastRemoteObject implements RMI{

	public static void main(String[] args) {
		 
		try {
			P2 s=new P2();
			Registry reg=LocateRegistry.createRegistry(2004);
			reg.rebind("SD", s);
			
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

	protected P2() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	public void Data(int a) throws RemoteException {
		// TODO Auto-generated method stub
		
		String m=Integer.toString(a*a);
		System.out.println(a+"*"+a+"="+m);
		Socket c;
		try {
			c = new Socket("localhost",2005);
			ObjectOutputStream out=new ObjectOutputStream(c.getOutputStream());
			out.writeObject(m);
		
			/*Retoure
			Recive data from P3
			 ObjectInputStream in=new ObjectInputStream(c.getInputStream()); 
			 String obj =(String) in.readObject(); 
			  System.out.println("P2 recive from P3 : obj="+obj);
			*/
		
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("holla.");
	
		
	}

}
