/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chatapp.filesharing;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

/**
 *
 * @author Rajat
 */
public class OpenClientStreams {
    Socket clientSocket;
    InputStream is;
    OutputStream os;
    public void openStreams() throws IOException{
        clientSocket = new Socket("127.0.0.1", 5995);
        System.out.println("Connecting...");
        is = clientSocket.getInputStream();
        os = clientSocket.getOutputStream();
        System.out.println("Connected to server");
    }
}
