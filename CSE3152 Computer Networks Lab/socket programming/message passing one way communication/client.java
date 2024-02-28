import java.net.*;
import java.io.*;
import java.util.*;
public class client {
    public static void main(String[] args) throws IOException{
        
        //create socket to connect with server

        Socket connect = new Socket("localhost",80);

        //Get I/O stream
        //sent info to server = OutputStream

        DataOutputStream dout = new DataOutputStream(connect.getOutputStream());
        String str;
        Scanner sc = new Scanner(System.in);
        
        while(true){
            str = sc.nextLine();
            if(str.equals("stop")) break;
            else{
                dout.writeUTF(str);
                dout.flush();
            }
        }
    
        
        dout.writeUTF(str);
        dout.flush();
        //close connection
        dout.close();
        sc.close();
        connect.close();
        
    }
}