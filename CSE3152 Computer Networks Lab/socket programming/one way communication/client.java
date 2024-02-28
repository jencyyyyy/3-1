import java.net.*;
import java.io.*;

public class client {
    public static void main(String[] args) throws IOException{
        
        //create socket to connect with server

        Socket connect = new Socket("localhost",80);

        //Get I/O stream

        //sent info to server = OutputStream
        PrintWriter out = new PrintWriter(connect.getOutputStream());
        out.println("Hello Server!!!");
        out.flush();

        //close connection
        out.close();
        connect.close();
        
    }
}