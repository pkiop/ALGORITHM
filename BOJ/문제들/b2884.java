

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();

		b -= 45;
		if(b < 0) {
			b += 60;
			a -= 1;
		}
		if(a < 0) {
			a += 24;
		}

		System.out.print(a);
		System.out.print(' ');
		System.out.print(b);
		sc.close();

	}
}
