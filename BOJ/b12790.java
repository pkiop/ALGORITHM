import java.util.Scanner;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		boolean[] bbb = new boolean[31];
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int aa,bb,cc,dd;
		while(t-- != 0) {
			int a,b,c,d;
			aa = sc.nextInt();
			bb = sc.nextInt();
			cc = sc.nextInt();
			dd = sc.nextInt();
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			d = sc.nextInt();
			aa += a;
			if(aa < 1) {
				aa = 1;
			}
			bb += b;
			if(bb < 1) {
				bb = 1;
			}
			cc += c;
			if(cc < 0) {
				cc = 0;
			}
			dd += d;
			System.out.println(aa + 5*bb + 2 * cc + 2 * dd);
		}
		
		sc.close();
	}
}