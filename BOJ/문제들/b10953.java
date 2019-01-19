import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a,b,t;
		t = sc.nextInt();
		while(t-- != 0) {
			String s = sc.next();
			String temp[] = s.split(",");
			a = Integer.parseInt(temp[0]);
			b = Integer.parseInt(temp[1]);
			System.out.println(a + b);
		}
		sc.close();
	}
}
