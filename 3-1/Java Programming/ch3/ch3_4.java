package ch3_pt;

import java.util.Scanner;
import java.util.InputMismatchException;

public class ch3_4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String[] day = {"일", "월", "화", "수", "목", "금", "토"};

        while (true) {
            try {
                System.out.print("정수를 입력하세요>>");
                int integer = scanner.nextInt(); 
                
                if (integer == -1) {
                    System.out.println("프로그램을 종료합니다...");
                    break;
                }
                System.out.println(day[integer % 7]);
            } catch (InputMismatchException e) {
                System.out.println("경고! 수를 입력하지 않았습니다.");
                scanner.nextLine();
            }
        }
        scanner.close();
    }
}
