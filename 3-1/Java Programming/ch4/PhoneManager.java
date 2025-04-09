package ch4_pt;
import java.util.Scanner;

class Phone {
	String name, tel;
	
	public Phone(String name, String tel) {
		this.name = name;
		this.tel = tel;
	}
	
	public String getName() {
		return name;
	}
	
	public String getTel() {
		return tel;
	}
}

public class PhoneManager {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("인원수>>");
		int num = scanner.nextInt();
		Phone[] phone = new Phone[num];
		
		for(int i=0; i<num; i++) {
			System.out.print("이름과 전화번호 입력>>");
			String name = scanner.next();
			String tel = scanner.next();
			
			phone[i] = new Phone(name, tel);
		}
		
		System.out.println("저장되었습니다...");
		
		while(true) {
			System.out.print("검색할 이름>>");
			String name = scanner.next();
			String tel = null;
			
			if(name.equals("exit")) {
				System.out.println("프로그램을 종료합니다...");
				scanner.close();
				break;
			}
			
		    for (int i = 0; i < num; ++i) {
		        if (name.equals(phone[i].getName())) {
		            tel = phone[i].getTel();
		            break;
		        }
		    }
		    
			if(tel==null) {
				System.out.println(name+"이 없습니다.");
			}
			else {
				System.out.println(name + "의 번호는 " + tel + " 입니다.");
			}
		}
	}
}