package javaprograms;

import java.util.Scanner;

public class arraysum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner S=new Scanner(System.in);
		int n=S.nextInt();
		int[] arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=S.nextInt();
		}
		System.out.println(printsum(arr));
	}
	
	static int printsum(int[]arr) {
		int sum=0;
		for(int i=0;i<arr.length;i++) {
			sum=sum+arr[i];
		}
		return sum;
	}

}
