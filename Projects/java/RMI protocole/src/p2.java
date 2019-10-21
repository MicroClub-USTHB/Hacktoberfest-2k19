import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class p2 extends java.rmi.server.UnicastRemoteObject implements ip2{

	protected p2() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	public int add(int a, int b) throws Exception {
		// TODO Auto-generated method stub
		return a+b;
	}

	@Override
	public int mult(int a, int b) throws Exception {
		// TODO Auto-generated method stub
		return a*b;
	}
	
	
	
	public static void main(String[] args) {
 
		try {
			p2 s=new p2();
			Registry reg=LocateRegistry.createRegistry(2004);
			reg.rebind("SD", s);
			
		} catch (RemoteException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}


}
