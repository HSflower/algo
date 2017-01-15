import java.util.ArrayList;
import java.util.Scanner;


public class IfoverAvg_4344 {

	public static void main(String[] args){
		double testcase;
		Scanner sc = new Scanner(System.in);
		testcase = sc.nextDouble();
		double[][] student = new double[101][1001];
		ArrayList<Double> avg = new ArrayList<Double>();
		for(int i = 0 ; i<testcase ; i++){
			double sum = 0;
			student[i][0] = sc.nextDouble();
			for(int j = 1; j<=student[i][0] ; j++){
				student[i][j] = sc.nextDouble();
				sum = sum + student[i][j];
			}
			avg.add( sum / student[i][0] );
		}
		for(int i = 0 ; i<testcase; i++){
			int count = 0 ;
			for(int j=1; j<=student[i][0]; j++){
				if(student[i][j] > avg.get(i)){
					count ++;
				}
			}
			String suffix = String.format("%.3f", (double)count/(double)student[i][0]*100);
			System.out.println( suffix + "%" );
		}
		
	}
}
