
package chatapp.chat;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Rajat
 */
public class Server {
    public static void main(String[] args) throws IOException{
        //System.out.println("Server is waiting for clients to initiate chat.....");
        CreateServerThread Server=new CreateServerThread(3000);
        
        //CreateClientThread client1=new CreateClientThread(3001);
        System.out.println("Server thread created on 3000");
        Server.runServer(3000);
        
        //System.out.println("Client connected to 3001");
        //client1.client_thread.start();
        try {
            Server.server_thread.join();
            //client1.client_thread.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

