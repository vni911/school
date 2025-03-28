package ch3_pt;

import java.util.Scanner;

public class ch3_1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("알파벳 한 문자를 입력하세요>> ");
        String s = scanner.next();
        char c = s.charAt(0);
        
        if ('a' <= c && c <= 'z') {
            for (char ch = 'a'; ch < c; ch++) {
                System.out.print(ch + " ");
            }
        } else {
            System.out.println("소문자가 아닙니다.");
        }

        scanner.close();
    }
}
