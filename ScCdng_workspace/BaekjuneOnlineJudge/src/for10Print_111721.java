import java.util.Scanner;

/**
 * @author Hanseul 
 * practice baekjune online judge
 */
public class for10Print_111721 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//���ĺ� �ҹ���, �빮��, ���� 1�̻� 100���� �Է�
		Scanner sc = new Scanner(System.in);
		String inputs = sc.nextLine(); //next()�� �ܾ�, nexLine�� �� ��, nextInt�� ����
		//�ٷ� ������ �Է�
//		InputStreamReader sr = new InputStreamReader(System.in);
//		BufferedReader br = new BufferedReader(sr);
//		String inputs = br.readLine();
// sr�� �ѱ���(char)�� �о���̰�, br�κ����� �� ��(string) �Է��� ����
// InputStream �� �� byte�� �Է� ����		
		
		//�����ھ� ���, 
		int x = inputs.length()%10; 
		if(x != 0) {
			for(int i = 0 ; i<inputs.length()-x ; i=i+10){
				System.out.println(inputs.substring(i, i+10));
			}
			System.out.println(inputs.substring(inputs.length()-(x), inputs.length()));
		}
		else {
			for(int i = 0 ; i<inputs.length() ; i=i+10){
				System.out.println(inputs.substring(i, i+10));
			}
		}
	}

}
