import java.io.EOFException;
import java.rmi.Remote;

public interface ip2 extends Remote{
int add(int a, int b) throws Exception ;
int mult (int a ,int b)throws Exception;
		
}
