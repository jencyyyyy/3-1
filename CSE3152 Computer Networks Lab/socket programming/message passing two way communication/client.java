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
        DataInputStream din = new DataInputStream(connect.getInputStream());
        String strC,strS;
        Scanner sc = new Scanner(System.in);
        
        while(true){
            System.out.println("(me)Client message: ");
            strC = sc.nextLine();
            if(strC.equals("stop")) break;

            else{
                dout.writeUTF(strC);
                dout.flush();
                strS = (String) din.readUTF();
                System.out.println("Server Message: "+ strS);
            }
        }
    
        
        dout.writeUTF("Client closing");
        dout.flush();
        //close connection
        dout.close();
        sc.close();
        connect.close();
        
    }
}