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
		//알파벳 소문자, 대문자, 길이 1이상 100이하 입력
		Scanner sc = new Scanner(System.in);
		String inputs = sc.nextLine(); //next()는 단어, nexLine은 한 줄, nextInt는 정수
		//바로 데이터 입력
//		InputStreamReader sr = new InputStreamReader(System.in);
//		BufferedReader br = new BufferedReader(sr);
//		String inputs = br.readLine();
// sr로 한글자(char)씩 읽어들이고, br로보내서 한 줄(string) 입력을 받음
// InputStream 은 한 byte씩 입력 가능		
		
		//열글자씩 출력, 
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
