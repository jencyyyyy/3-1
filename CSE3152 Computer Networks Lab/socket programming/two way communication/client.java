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

        BufferedReader in = new BufferedReader(
            new InputStreamReader(connect.getInputStream()
            ));

        String str = in.readLine();
        
        System.out.println("Server Message: "+ str);

        //close connection
        in.close();
        out.close();
        connect.close();
        
    }
}