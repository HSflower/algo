import java.util.Scanner;


public class if1110plusCycle {

	public static void main(String[] args) {

		int testcase = 0;
		Scanner sc = new Scanner(System.in);
		testcase = sc.nextInt();
		
		if( testcase >=0 && testcase<=99){
			int cons = 0;
			int subcons = 0;
			int count = 0;
			//첫 cons설정
			if(cons == testcase) count=1;
			else {
				while(cons != testcase){
					if(count==0) cons = testcase; //1회시, 초기화
					
					if(cons <10) cons = cons*10 + cons;
					else {
						subcons = cons/10 + cons%10; //2+6=8
						if(subcons < 10) {
							cons = subcons + (cons%10)*10;
						}
						else {
							cons = subcons%10 + (cons%10)*10;
						}
					}
					count++;
				}
			}
			System.out.println(count);
		}
		else {
			System.out.println("0");
		}
	}

}
