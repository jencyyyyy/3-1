import java.net.*;
import java.io.*;

public class server {
    public static void main(String[] args) throws IOException{
        
        //create socket to connect with server

        ServerSocket server = new ServerSocket(80);

        //wait for client
        System.out.println("Waiting for client---");

        //Accept client request
        Socket conn = server.accept();
        System.out.println("Client connected");
        
        
        //Get I/O stream
        //receiv info from client = InputStream
        //sent info to client = OutputStream
        BufferedReader in = new BufferedReader(
            new InputStreamReader(conn.getInputStream()
            ));

        String str = in.readLine();
        
        System.out.println("Client Message: "+ str);

        //close connection
        in.close();
        conn.close();
        server.close();
        
    }
}