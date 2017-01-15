import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Ifxnum_10871 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		List<Integer> intArray = new ArrayList<Integer>();
		for(int i = 0 ; i<n ; i++){
			intArray.add(sc.nextInt());
		}
		//Collections.sort(intArray);
		for(int i = 0 ; i<n; i++) {
			if(intArray.get(i) < x) System.out.print(intArray.get(i)+" ");
		}
	}

}
