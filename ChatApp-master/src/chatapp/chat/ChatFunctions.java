/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package chatapp.chat;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 *
 * @author Rajat
 */
public class ChatFunctions {
    ServerSocket serverSocket;
    Socket client_socket;
    PrintWriter toClient, toServer;
    BufferedReader fromClient, fromServer;
    
    public void openServerStreams(Socket socket,int port) throws IOException{
        toClient = new PrintWriter(socket.getOutputStream(),true);
        fromClient = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        System.out.println("Connected : "+ socket);
    }
    public void closeServerStreams(Socket socket) throws IOException{
        fromClient.close();
        toClient.close();
        socket.close();
        serverSocket.close();
   }
   public void openClientStreams(Socket socket, int port) throws UnknownHostException, IOException{
        //client_socket = new Socket("127.0.0.1",port);
        toServer = new PrintWriter(socket.getOutputStream(),true);
        fromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    }
    public void closeClientStreams(Socket socket) throws IOException{
        fromServer.close();
        toServer.close();
        socket.close();
    }   
}

