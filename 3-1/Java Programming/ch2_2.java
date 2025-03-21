package ch2_pt;
import java.util.Scanner;

public class ch2_2 {
	public static void main(String[] args) {
		System.out.print("몇 층인지 입력하세요>> ");
		Scanner scanner = new Scanner(System.in);
		int height = scanner.nextInt();
		int floor = height * 5;
		System.out.print(floor +"m 입니다.");
	}
}
