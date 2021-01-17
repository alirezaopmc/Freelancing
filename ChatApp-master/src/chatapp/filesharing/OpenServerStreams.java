
package chatapp.filesharing;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
/**
 *
 * @author Rajat
 */
public class OpenServerStreams {
    ServerSocket serverSocket;
    Socket socket;
    OutputStream os;
    InputStream is;
    OpenServerStreams() throws IOException{
        serverSocket = new ServerSocket(5995);
    }
    public void openStreams() throws IOException{
        socket = serverSocket.accept();
        System.out.println("Server Started...waiting for client..");
        System.out.println("Accepted connection : " + socket);
        os = socket.getOutputStream();
        is = socket.getInputStream();
    }
}

