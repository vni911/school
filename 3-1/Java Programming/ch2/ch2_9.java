package ch2_pt;
import java.util.Scanner;

public class ch2_9 {
	public static void main(String[] args) {
		System.out.print("1~99 사이의 정수를 입력하세요>>");
		Scanner scanner = new Scanner(System.in);
		
		int val = scanner.nextInt();
		int first = val/10;
		int second = val%10;
		
		if(first == 3 || first == 6 || first == 9) {
			if(second == 3 || second == 6 || second == 9) {
				System.out.println("박수짝짝");
			} else {
				System.out.println("박수짝");
			}
		} else {
			if(second == 3 || second == 6 || second == 9) {
				System.out.println("박수짝");
			} else {
				System.out.println("박수없음");
			}
		}
	}
}
