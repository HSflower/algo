
public class functionSelfNum_4673 {

	public static void main(String[] args) {
		int[] arr = new int[10001];
		
		for(int i=0; i<=10000; i++){
			int x = selfNum(i);
			if(x > 10000) continue;
			else {
				if(arr[x]==1) continue;
				else arr[x] = 1; 
			}
		}
		
		for(int i=0 ;i<=10000; i++){
			if(arr[i]==0) System.out.println(i);
		}
		
	}

	protected static int selfNum(int n){
		String s = n+"";
		int length = s.length();
		if(length==1) return n+n;
		else{
			for(int i = 0; i<length; i++){
				int m = s.charAt(i);
				n = n + m-48;
			}
			return n;
		}
	}
}
