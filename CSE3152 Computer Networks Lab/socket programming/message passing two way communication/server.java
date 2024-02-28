import java.net.*;
import java.util.Scanner;
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
        
        Scanner sc = new Scanner(System.in);
        //Get I/O stream
        //receiv info from client = InputStream
        //sent info to client = OutputStream
        DataInputStream dis = new DataInputStream(
            conn.getInputStream()
            );

        DataOutputStream dout = new DataOutputStream(conn.getOutputStream());
     
        
        String strC,strS;

        while(true){
            strC = (String) dis.readUTF();
            System.out.println("Client = "+strC);
            System.out.println("Server message: ");
            strS = sc.nextLine();
            if (strS.equals("stop")) break;
            else {
                dout.writeUTF(strS);
                dout.flush();
            }
        }


        
            dout.writeUTF("Server is closing");
            dout.flush();
            dout.close();

        //close connection
        sc.close();

        server.close();
        
    }
}