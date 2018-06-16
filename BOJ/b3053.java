import java.util.Scanner;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		
		double ansa = r*r*Math.PI;
		String num = String.format("%.6f", ansa);
		double ansb = r*r*2;
		String num2 = String.format("%.6f", ansb);
		System.out.println(num);
		System.out.println(num2);
		sc.close();
	}
}