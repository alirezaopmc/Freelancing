
package chatapp.filesharing;

import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Rajat
 */
public class FileClient {
    static Scanner sc;
    public static void main (String[] args) throws IOException{
        sc = new Scanner (System.in);
        FileFunctions ff = new FileFunctions("Client");
        ff.receiveFilefromServer("fromServer.txt");
        System.out.println("Enter name or path of the file to be sent :");
        String fileName = sc.nextLine();
        ff.sendFiletoServer(fileName);
    } 
}
