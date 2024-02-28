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
        DataInputStream dis = new DataInputStream(
            conn.getInputStream()
            );
        
        String str;

        while(true){
            str = (String) dis.readUTF();
            if (str.equals("stop")) break;
            else {
                System.out.println("message : " + str); // showing the message
            }
        }

        
        System.out.println("Client Message: "+ str);

        //close connection

        server.close();
        
    }
}