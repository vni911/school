package ch2_pt;
import java.util.Scanner;

public class ch2_4 {
	public static void main(String[] args) {

		System.out.print("점 (x,y)의 좌표를 입력하세요>>");
		Scanner scanner = new Scanner(System.in);

		int x_val = scanner.nextInt();
		int y_val = scanner.nextInt();

		if(50 <= x_val && x_val <= 100) {
			if(50 <= y_val && y_val <= 100) {
				System.out.println("점("+x_val+", "+y_val+")은 (50, 50)과 (100, 100)의 사각형 내에 있습니다.");
			}
			else {
				System.out.println("점("+x_val+", "+y_val+")은 (50, 50)과 (100, 100)의 사각형 내에 없습니다.");
			}
		} else{
			System.out.println("점("+x_val+", "+y_val+")은 (50, 50)과 (100, 100)의 사각형 내에 없습니다.");
		}
	}
}
