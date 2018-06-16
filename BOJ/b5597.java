import java.util.Scanner;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		boolean[] bbb = new boolean[31];
		Scanner sc = new Scanner(System.in);
		int a;
		int t = 28;
		while(t-- != 0) {
			a = sc.nextInt();
			bbb[a] = true;
		}
		for(int i=1;i<=30;++i) {
			if(bbb[i] == false) {
				System.out.println(i);
			}
		}
		
		sc.close();
	}
}