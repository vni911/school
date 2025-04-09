package ch4_pt;
import java.util.Scanner;

class Rect {
	private int width, height;
	public Rect(int width, int height) {
		this.width = width;
		this.height = height;
	}
	public int getArea() { return width*height; }
}

public class RectArray {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Rect[] rect = new Rect[4];
		int sum = 0;
		
		for(int i=0; i<rect.length; ++i) {
			System.out.print((i+1) + " 너비와 높이 >>");
			int width = scanner.nextInt();
			int height = scanner.nextInt();
			
			rect[i] = new Rect(width, height);
			sum += rect[i].getArea();
		}
			
		System.out.println("저장하였습니다...");
		System.out.println("사각형의 전체 합은 " + sum);
		scanner.close();
	}
}
