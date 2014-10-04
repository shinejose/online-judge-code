import java.io.*;
import java.util.*;
import java.math.*;

public class sgu111{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	BigInteger l,r,mid,x,two,one ,ans;
	two = BigInteger.valueOf(2);
	one = BigInteger.valueOf(1);
	x = sc.nextBigInteger();
	l = BigInteger.ZERO;
	ans =BigInteger.ZERO;
	r = x;
	while ( l.compareTo(r) <= 0 ){
	    mid = l.add(r).divide(two);
	    if(mid.multiply(mid).compareTo(x) <= 0 ){
		l = mid.add(new BigInteger("1"))  ;
		ans = mid;
	    }
	    else
		r = mid.subtract(new BigInteger("1") )  ;
	}
	System.out.println(ans);
    }
}

















