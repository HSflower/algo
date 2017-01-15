import java.util.Arrays;
import java.util.Scanner;


public class IfAverage_1546 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); // <=1000
		double [] arr = new double[1000]; // <=100 , >=0, 적어도 하나 >0
		//a,b,c가 아니라 arr로 n개 받기
		//if((a>0 || b>0 || c>0) && (a>0&&b>0&&c>0) && a<=100 && b<=100 && c<=100 && n<=1000){
		for( int i = 0 ; i<n; i++){
			arr[i] = (double)sc.nextInt();
			if(!(arr[i]>=0 && arr[i]<=100)) System.out.println("error");
		}
		
		Arrays.sort(arr);
		double m = arr[999];
		double sum = 0.0 ;
		int count = 0 ;
		for(int i = 999; i>=1000-n ; i--) {
			arr[i] = (arr[i]/m)*100;
			sum = sum + arr[i];
			if(arr[i]>0) count++;
		}
		if(count==0) System.out.println("error");
		else{
			String suffix = String.format("%.2f", sum/n);
			System.out.println( suffix  );
		}
	}
}
