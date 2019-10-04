import java.io.*;
public class Sort {
	// function to sort the given array and return it
	static int[] Ssort(int a[]) {
		int l=a.length;
		for(int i=0;i<l-1;i++) {
			int min=a[i];int p=i;
			for(int j=i+1;j<l;j++) {
				if(a[j]<min) {
					min=a[j];
					p=j;
				}
			}
			int t=a[i];
			a[i]=a[p];
			a[p]=t;
		}
		return a;
	}
	// main method to take input and give final output
	public static void main(String[] args)throws IOException {
		BufferedReader ob=new BufferedReader(new InputStreamReader(System.in));
		String s[]=ob.readLine().split(" "); //input by user
		int a[]=new int[s.length];
		for(int i=0;i<s.length;i++)
			a[i]=Integer.parseInt(s[i]);
		a=Ssort(a);
		for(int i=0;i<a.length;i++) //printing the sorted array
			System.out.print(a[i]+" ");
	}

}
