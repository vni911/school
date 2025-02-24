//22110670 김정운//

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class HW2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String filename;

        while (true) {
            System.out.print("파일 이름을 입력하세요: ");
            filename = scan.nextLine();
            File file = new File(filename);
            if (file.exists()) {
                break;
            } else {
                System.out.println("파일이 없습니다. 다시 입력하세요.");
            }
        }

        distance calculator = new distance();
        try {
            calculator.scanfile(filename);
        } catch (FileNotFoundException e) { // 예외처리
        }
        calculator.distance(); //단순한 방법, 똑똑한 방법

        scan.close(); 
    }
}

class location {
    int x, y;

    location(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class distance {
    private List<location> A = new ArrayList<>();
    private List<location> B = new ArrayList<>();

    public void scanfile(String filename) throws FileNotFoundException {
        Scanner file_scanner = new Scanner(new File(filename));
        while (file_scanner.hasNextLine()) {
            String line = file_scanner.nextLine();
            String[] value = line.split(" "); //띄어쓰기로 구분

            if (value.length < 2) {
                continue; // A, B 갯수 말해줄 때 오류발생
            }
            
            int x = Integer.parseInt(value[0]);
            int y = Integer.parseInt(value[1]);

            if (x < 0) {
                A.add(new location(x, y));
            } else { 
                B.add(new location(x, y));
            }
        }
        file_scanner.close();
    }

    public void distance() {
        simple_distance();
        smart_distance();
    }

    //단순한 방법
    private void simple_distance() {
        long start = System.currentTimeMillis(); //시작
        location nearA = null;
        location nearB = null;
        int simple_distance = Integer.MAX_VALUE;

        for (location a : A) {
            for (location b : B) {
                int distance = Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
                if (distance < simple_distance) {
                    simple_distance = distance;
                    nearA = a;
                    nearB = b;
                }
            }
        }

        long stop = System.currentTimeMillis(); // 종료
        print_results("단순한 방법", simple_distance, nearA, nearB, stop - start);
    }
    
    //똑똑한 방법
    private void smart_distance() {
        List<location> nearA_smart = a_xlist(A);
        List<location> nearB_smart = b_xlist(B);

        long start = System.currentTimeMillis(); //시작
        location nearA = null;
        location nearB = null;
        int smart_distance = Integer.MAX_VALUE;

        for (location a : nearA_smart) {
            for (location b : nearB_smart) {
                int distance = Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
                if (distance < smart_distance) {
                    smart_distance = distance;
                    nearA = a;
                    nearB = b;
                }
            }
        }

        long stop = System.currentTimeMillis(); //종료
        print_results("똑똑한 방법", smart_distance, nearA, nearB, stop - start);
    }

    //A에서 가장 오른쪽(큰) x값 리스트로 정리
    private List<location> a_xlist(List<location> locations) {
        List<location> result = new ArrayList<>();
        for (location a : locations) {
            boolean found = false;
            for (location optimal_xlist : result) {
                if (optimal_xlist.y == a.y) {
                    found = true;
                    if (a.x > optimal_xlist.x) {
                        result.remove(optimal_xlist); //필요없는 위치 지우기
                        result.add(a);
                    }
                    break;
                }
            }
            if (!found) {  //y선상에 x가 하나일 때 문제발생
                result.add(a);
            }
        }
        return result;
    }

    //B에서 가장 왼쪽(작은) x값 리스트로 정리    
    private List<location> b_xlist(List<location> locations) {
        List<location> result = new ArrayList<>();
        for (location b : locations) {
            boolean found = false;
            for (location optimal_xlist : result) {
                if (optimal_xlist.y == b.y) {
                    found = true;
                    if (b.x < optimal_xlist.x) {    //필요없는 위치 지우기
                        result.remove(optimal_xlist);
                        result.add(b);
                    }
                    break;
                }
            }
            if (!found) {  //y선상에 x가 하나일 때 문제발생 
                result.add(b);
            }
        }
        return result;
    }

    //결과 출력
    private void print_results(String method, int distance, location nearA, location nearB, float duration) {
        System.out.println("\n" + method + " 최단 거리: " + distance);
        System.out.println("i(" + nearA.x + ", " + nearA.y + "), p(" + nearB.x + ", " + nearB.y + ")");
        System.out.printf("실행 시간: %.2f초\n", duration / 1000.0);
    }
}