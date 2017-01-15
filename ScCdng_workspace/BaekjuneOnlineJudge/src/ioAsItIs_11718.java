import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class ioAsItIs_11718 {

	@SuppressWarnings("null")
	public static void main(String[] args) throws IOException {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//char c = (char)br.read();
		InputStreamReader isr = null;
		OutputStreamWriter osw = null;
		
		isr = new InputStreamReader(System.in);
		osw = new OutputStreamWriter(System.out);
		int i = 0;
		
		InputStreamReader r = new InputStreamReader(System.in);
        BufferedReader b = new BufferedReader(r);
        String userInput = b.readLine();
        System.out.println("user input :"+userInput);
        
		while((i=isr.read())!=-1){
			osw.write((char)i);
		}
	}

}
