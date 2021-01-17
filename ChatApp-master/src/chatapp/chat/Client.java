
package chatapp.chat;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Rajat
 */
public class Client {
    public static void main (String[] args) throws java.lang.NullPointerException, IOException{
        //System.out.println("Start of the program");
        CreateServerThread Server=new CreateServerThread(3002);
        System.out.println("Server running on port 3002");
        //CreateClientThread client1 = new CreateClientThread(3000);
        
        Server.runServer(3001);
        try {
            //client1.client_thread.join();
           Server.server_thread.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("End of the program");
    }
}