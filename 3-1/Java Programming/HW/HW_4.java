import java.util.Scanner;
import java.util.InputMismatchException;


class BookDB{
	String[] books;
	int count;

	public BookDB() {
		books = new String[3];
		count = 0;
	}
	
	public boolean addBook(String name) {
		if(count >= books.length) {
			return false;
		} else { 
			books[count++] = name; //인덱스 나중에 추가
			return true;
			}
		}

    public boolean deleteBook(String name) {
        for (int i = 0; i < count; i++) {
            if (books[i].equals(name)) {
                for (int j = i; j < count - 1; ++j) {
                    books[j] = books[j + 1];
                }
                books[--count] = null;
                return true;
            }
        }
        return false;

   }
  
	public int size() {
		return count;
	}

	public void printBooks() {
		if (count == 0) {
			System.out.println("책이 없습니다.");
		return;
		}
		
		for (int i = 0; i < count; ++i) {
            System.out.println("번호: " + (i + 1) + ", 책 제목: " + books[i] + "\n");
        }
	}
}

public class HW_4 {
	public static void main(String[] args) {
		BookDB db = new BookDB();
		Scanner scanner = new Scanner(System.in);
		while (true) {
			try {
				System.out.println("1. addBook  2. deleteBook 3.size 4.printBooks 5.종료 ");
				System.out.println("메뉴 선택 >>");
				int choice = scanner.nextInt();
				scanner.nextLine();
				
	            switch (choice) {
	            	case 1: //addBook()
	            		System.out.print("추가할 책 제목 >> ");
	            		String addName = scanner.nextLine();
	            		if (db.addBook(addName)) {
	            			System.out.println("책이 추가되었습니다.\n");
	            		} else {
	            			System.out.println("책을 더 이상 추가할 수 없습니다.\n");
	            		}
	            		break;
	
	            	case 2: //deleteBook()
	            		System.out.print("삭제할 책 제목 >> ");
	            		String delName = scanner.nextLine();
	            		if (db.deleteBook(delName)) {
	            			System.out.println("책이 삭제되었습니다.\n");
	            		} else {
	            			System.out.println("해당 책을 찾을 수 없습니다.\n");
	            		}
	            		break;
	
	            	case 3: //size()
	            		System.out.println("현재 책 수: " + db.size() + "\n");
	
	            		break;
	
	            	case 4: //printBooks()
	            		db.printBooks();
	            		break;
	            	
	            	case 5:
	            		System.out.println("종료합니다.");
	            		scanner.close();
	            		return;
	
	            	default:
	            		System.out.println("올바른 번호를 입력하세요.");
	            }
			} catch (InputMismatchException e) {
				System.out.println("숫자를 입력해주세요.\n");
				scanner.nextLine();
			}
		}
	}
}