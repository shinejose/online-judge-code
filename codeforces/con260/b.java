import java.util.*;
import java.io.*;
import java.math.*;

public class b{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	String 	n = sc.next();

	int base=1;
	int ans =0;
	for(int i = n.length()-1;i>=0;i--) {
	    ans =( ans + (base * ( (n.charAt(i)-'0') %4))%4 )%4;
	    base = (base *10 ) %4;
	}
	int m =( 1 + (int) Math.pow(2,ans)+ (int)Math.pow(3,ans)+(int)Math.pow(4,ans)  )% 5 ;
	System.out.println(m);
    }
}



















