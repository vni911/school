package ch4_pt;
import java.util.Scanner;

public class Phone {
	private String name, tel;
	public Phone(String name, String tel) {
		this.name = name;
		this.tel = tel;
	}
	public String getName() { return name; }
	public String getTel() { return tel; }
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Phone phone[] = new Phone[2];
		
		for(int i=0; i<phone.length; ++i) {
			System.out.print("이름과 전화번호 입력 >>");
			String name = scanner.next();
			String tel = scanner.next();
			
			phone[i] = new Phone(name ,tel);
		}
		
		for(int i=0; i<phone.length; ++i) {
			System.out.println(phone[i].getName() + "의 번호 " + phone[i].getTel());
		}
		
		scanner.close();
	}
}
