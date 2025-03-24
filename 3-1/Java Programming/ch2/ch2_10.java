package ch2_pt;
import java.util.Scanner;

public class ch2_10 {
	public static void main(String[] args) {
		System.out.print("커피주문하세요>>");
		Scanner scanner = new Scanner(System.in);
		
		String menu = scanner.next();
		int count = scanner.nextInt();
		
		
		switch(menu) {
			case("에스프레소"):
				if(count >= 10) {
					System.out.println((int)(2000*count*0.95)+"원입니다.");
					break;
				} else {
					System.out.println(2000*count+"원입니다.");
					break;
				}
			case("아메리카노"):
				System.out.println(2500*count+"원입니다.");
				break;
			case("카푸치노"):
				System.out.println(3000*count+"원입니다.");
				break;
			case("카페라떼"):
				System.out.println(3500*count+"원입니다.");
				break;
			default:
				System.out.println("메뉴가 없거나 잘못입력하였습니다");
				scanner.close();
				return;
	}
		/*
		if(menu.equals("에스프레소")) {
			if(count >= 10) {
				System.out.println((int)(2000*count*0.95)+"원입니다.");
			} else {
				System.out.println((2000*count)+"원입니다.");
			}
		} else if(menu.equals("아메리카노")) {
			System.out.println(2500*count+"원입니다.");
		} else if(menu.equals("카푸치노")) {
			System.out.println(3000*count+"원입니다.");
		} else if(menu.equals("카페라떼")) {
			System.out.println(3500*count+"원입니다.");
		} else {
			System.out.println("메뉴가 없습니다");
			scanner.close();
			return;
		}*/	
	}
}
