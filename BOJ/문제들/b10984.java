import java.util.Scanner;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- != 0) {
			int n = sc.nextInt();
			int nn = n;
			int ans = 0;
			float ans2 = (float) 0.0;
			while(n-- != 0) {
				int a = sc.nextInt();
				float b = sc.nextFloat();
				ans += a;
				ans2 += a*b;
			}
			String ans3 = String.format("%.1f", ans2/ans);
			System.out.print(ans);
			System.out.print(' ');
			System.out.println(ans3);
		}
		sc.close();
	}
}