import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s2 = sc.next();
		int len = s2.length();
		for(int i=0;i<len;++i) {
			System.out.print(s2.charAt(i));
			if((i+1)%10 == 0) {
				System.out.println();
			}
		}
		sc.close();


	}

}
