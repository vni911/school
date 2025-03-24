package ch2_pt;
import java.util.Scanner;

public class ch2_6 {
	public static void main(String[] args) {
		System.out.print("돈의 액수를 입력하세요>>");
		Scanner scanner = new Scanner(System.in);
		
		int count;
		int val = scanner.nextInt();
		
		count = val/50000;
		System.out.print("오만원권"+count+"개, ");
		val %= 50000;

		count = val/10000;
		System.out.print("만원권"+count+"개, ");
		val %= 10000;

		count = val/1000;
		System.out.print("천원권"+count+"개, ");
		val %= 1000;
		
		count = val/500;
		System.out.print("500원권"+count+"개, ");
		val %= 500;
		
		count = val/100;
		System.out.print("100원권"+count+"개, ");
		val %= 100;
		
		count = val/10;
		System.out.print("10원권"+count+"개, ");
		val %= 10;
		
		System.out.print("1원권"+count+"개");
	}		
}
