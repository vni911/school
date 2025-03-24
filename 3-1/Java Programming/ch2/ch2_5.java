package ch2_pt;
import java.util.Scanner;

public class ch2_5 {
	public static void main(String[] args) {
		System.out.print("논리 연산을 입력하세요>>");
		Scanner scanner = new Scanner(System.in);
		
		boolean logic_1 = scanner.nextBoolean();
		String sel = scanner.next();
		boolean logic_2 = scanner.nextBoolean();
		
		switch (sel) {
			case("AND") :
				System.out.println(logic_1&logic_2);
			case("OR") :
				System.out.println(logic_1|logic_2);
		}
	}
}
