import java.rmi.Remote;
import java.rmi.RemoteException;

// Remote interface for Bank Account operations
public interface BankAccount extends Remote {
    double getBalance(String accountNumber) throws RemoteException;
    
    void deposit(String accountNumber, double amount) throws RemoteException;
    
    void withdraw(String accountNumber, double amount) throws RemoteException;
    
    String getAccountHolder(String accountNumber) throws RemoteException;
}
