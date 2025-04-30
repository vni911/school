import java.util.Scanner;
import java.util.*;


class Book {
	String title;
	int total;
	
	public Book(String title, int total) {
		this.title = title;
		this.total = total;
	}
}

class BookDB {
    ArrayList<Book> bookList = new ArrayList<>();

    public boolean registerBook(String title, int total) {
        for (Book b : bookList) {
            if (b.title.equals(title)) {
                b.total += total;
                System.out.println("전체 책의 수 : "+ b.total);
                return true;
            }
        }
        bookList.add(new Book(title, total));
        System.out.println("전체 책의 수 : "+ total);
        return true;
    }

    public boolean searchBook(String title) {
        for (Book b : bookList) {
            if (b.title.equals(title)) {
                System.out.println("책 제목 : "+ b.title+ "\n전체 책의 수 : "+ b.total);
                return true;
            }
        }
        System.out.println("해당 도서가 없습니다.");
        return false;
    }

    public boolean leaseBook(String title) {
        for (Book b : bookList) {
            if (b.title.equals(title)) {
                if (b.total > 0) {
                    --b.total;
                    System.out.println("책 제목 : "+ b.title+ "\n전체 책의 수 : "+ b.total);
                    return true;
                } 
                System.out.println("수량이 부족합니다.");
                return false;
                
            }
        }
        System.out.println("해당 도서가 없습니다.");
        return false;
    }
}
		
public class Library {
    public static void main(String[] args) {
        BookDB db = new BookDB();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("1. 등록  2. 검색  3. 대여  4. 종료");
            System.out.print("메뉴 선택 >> ");
            int option = scanner.nextInt();
            scanner.nextLine();

            switch (option) {
                case 1:
                    System.out.print("등록할 책 제목: ");
                    String title = scanner.nextLine();
                    System.out.print("등록할 수량: ");
                    int count = scanner.nextInt();
                    db.registerBook(title, count);
                    break;
                case 2:
                    System.out.print("검색할 책 제목: ");
                    String searchTitle = scanner.nextLine();
                    db.searchBook(searchTitle);
                    break;
                case 3:
                    System.out.print("대여할 책 제목: ");
                    String leaseTitle = scanner.nextLine();
                    db.leaseBook(leaseTitle);
                    break;
                case 4:
                    System.out.println("프로그램 종료");
                    scanner.close();
                    return;
                default:
                    System.out.println("잘못된 입력입니다.");
            }
        }
    }
}