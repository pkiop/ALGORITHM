import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s2 = sc.next();
		long ans = 0;
		for(int i=0;i<n;++i) {
			ans += s2.charAt(i) - '0';
		}
		System.out.println(ans);
		sc.close();


	}

}
