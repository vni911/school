//22110670 김정운//

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class HW1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("숫자로 구성된 문자열을 입력하시오(length : 1~7): ");
        String numbers = scanner.nextLine();
        List<Integer> primenumber = new ArrayList<>();

        perm(numbers.toCharArray(), 0, primenumber);//숫자 -> 문자형
        Collections.sort(primenumber); //오름차순으로 정렬
        System.out.println("소수 갯수 : " + primenumber.size() +"개");
        System.out.println("소수: " + primenumber);

        scanner.close();
    }
    //순열 (ppt 21page)
    private static void perm(char[] A, int j, List<Integer> primenumber) {
        if (j == A.length) {
            String current = new String(A);
            add_str_num(current, primenumber);
            return;
        }
        for (int i = j; i < A.length; i++) {
            swap(A, j, i);
            perm(A, j + 1, primenumber);
            swap(A, j, i);
        }
    }
    private static void swap(char[] A, int i, int k){char temp = A[i]; A[i] = A[k]; A[k] = temp;}

    //문자열 찾기
    private static void add_str_num(String str, List<Integer> primenumber) {
        for (int len = 1; len <= str.length(); len++) {
            for (int position = 0; position <= str.length() - len; position++) {
                String strnumber = str.substring(position, position + len);
                int num = Integer.parseInt(strnumber);
                if (sel_prime(num) && !primenumber.contains(num)) {  //contain을 사용하여 중복 제거
                    primenumber.add(num);
                }
            }
        }
    }

    //소수 찾기
    private static boolean sel_prime(int num) {
        if (num < 2) return false;
        for (int a = 2; a < num; a++) {
            if (num % a == 0) return false;
        }
        return true;
    }
}