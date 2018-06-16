import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int a,b,c;
		while(t-- != 0) {
			a = sc.nextInt();
			b = sc.nextInt();
			c = sc.nextInt();
			
			b -= c;
			if(a > b) {
				System.out.println("do not advertise");
			}
			else if(a < b) {
				System.out.println("advertise");
			}
			else {
				System.out.println("does not matter");
			}
		}
		sc.close();

	}
}