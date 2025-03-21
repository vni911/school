import java.util.Scanner;

public class Ch2Challenge {
	public static void main(String[] args) {
		System.out.println("가위 바위 보 게임입니다. 가위, 바위, 보 중에서 입력하세요");
		System.out.print("철수 >>");
		Scanner scanner = new Scanner(System.in);
		String first = scanner.next();
		System.out.print("영희 >>");
		String second = scanner.next();
		
		
		if (first.equals("가위")) {
			switch(second) {
			case "가위":
				System.out.print("비겼습니다");break;
			case "바위":
				System.out.print("영희가 이겼습니다");break;
			case "보":
				System.out.print("철수가 이겼습니다");break;
			default:
				System.out.println("잘못된 입력입니다");
			}		
		}else if (first.equals("바위")) {
			switch(second) {
			case "가위":
				System.out.print("철수가 이겼습니다");break;
			case "바위":
				System.out.print("비겼습니다");break;
			case "보":
				System.out.print("영희가 이겼습니다");break;
			default:
			System.out.println("잘못된 입력입니다");
			}	
		}
		else if (first.equals("보")) {
			switch(second) {
			case "가위":
				System.out.print("영희가 이겼습니다");break;
			case "바위":
				System.out.print("비겼습니다");break;
			case "보":
				System.out.print("철수가 이겼습니다");break;
			default:
			System.out.println("잘못된 입력입니다");
			}	
		} else {
			System.out.println("잘못된 입력입니다");
		}
	}
}
