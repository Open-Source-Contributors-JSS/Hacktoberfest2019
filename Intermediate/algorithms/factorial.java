import java.util.*;

public class fac
{
 public static void main(String[] args)
 {
   int f=1;
   Scanner s=new Scanner(System.in);
   System.out.println("ENTER A NUMBER:");
   int n=s.nextInt();
  System.out.print("FACTORIAL IS :");
  for(int i=1;i<=n;i++)
  {
    f=f*i;
  }
  System.out.println(f);
 }
}
