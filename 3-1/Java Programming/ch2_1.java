package ch2_pt;
import java.util.Scanner;

public class ch2_1 {
	public static void main(String[] args) {
		System.out.print("두 정수를 입력하세요>>");
		Scanner scanner = new Scanner(System.in);
		int scan_1 = scanner.nextInt();
		int scan_2 = scanner.nextInt();
		int sum = scan_1 + scan_2;
		System.out.println(scan_1 + "+" + scan_2 + "은 "+ sum);
	}
}
