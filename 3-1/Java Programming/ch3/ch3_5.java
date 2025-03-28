package ch3_pt;

import java.util.Scanner;

public class ch3_5 {
    public static void main(String[] args) {
		
    	System.out.print("정수 10개 입력>>");
    	Scanner scanner = new Scanner(System.in);
    	int[] integer = new int[10];
    	
    	for (int i=0; i<integer.length; ++i) {
    		integer[i] = scanner.nextInt(); 
    	}
    	 
    	for (int i=0; i<integer.length-1; ++i) {
    		for(int j=0; j<integer.length-1-i; ++j) {
    			if(integer[j]>integer[j+1]) {
    	    		int temp = integer[j+1];
    	    		integer[j+1] = integer[j];
    	    		integer[j] = temp;
    	    	}
    		} 
    	}
    	
    	for (int i=0; i<integer.length; ++i) {
    		System.out.print(integer[i]+" ");
    	}
    }
}