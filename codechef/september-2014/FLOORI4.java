import java.io.*;
import java.util.*;
import java.math.*;

class PAIR{
    BigInteger first,second;
    public PAIR (BigInteger a,BigInteger b ){
        first = a ;
        second =b;
    }
}
class FLOORI4 {
    static BigInteger b_10 = new BigInteger("10");
    static BigInteger b_6 = new BigInteger("6");
    static BigInteger b_15 = new BigInteger("15");
    static BigInteger b_1  = new BigInteger("1");
    static BigInteger b_30 = new BigInteger("30");
    static PAIR [] vf = new PAIR [2000005] ;
    static int vfLen =0;

    public static  BigInteger Cal_S4(BigInteger n) {
        BigInteger nPlus1 = n.add(new BigInteger("1")) ;
        BigInteger nTimes2Plus1 = n.multiply(new BigInteger("2")).add(new BigInteger("1"));
        BigInteger ten = new BigInteger("10");
        BigInteger six = new BigInteger("6");
        BigInteger five = new BigInteger("5");
        BigInteger four = new BigInteger("4");
        BigInteger two = new BigInteger("2");
        BigInteger S0 = n ;
        BigInteger S1 = n.multiply(nPlus1).divide(two);
        BigInteger S2 = n.multiply(nPlus1).multiply(nTimes2Plus1).divide(six);
        BigInteger S3 = n.multiply(n).multiply(nPlus1).multiply(nPlus1).divide(four);
        BigInteger n5 = n.multiply(n).multiply(n).multiply(n).multiply(n) ;
        BigInteger S4 = n5.add(ten.multiply(S3)).subtract(ten.multiply(S2)).add(five.multiply(S1)).subtract(S0).divide(five);
        return S4;
    }
    
    public static BigInteger Cal_S4_2(BigInteger n){
        BigInteger []n_pow = new BigInteger [6];
        n_pow[1] = n ;
        for(int j =2;j<=5;j++){
            n_pow[j] = n_pow[j-1].multiply( n) ;
        }
        return b_6.multiply(n_pow[5]).add(b_15.multiply(n_pow[4])).add(b_10.multiply(n_pow[3])).subtract(n_pow[1]).divide(b_30);
    }
    public static   long MAXN = 1000000;
    public static int MAXCNT = 200005 ;
    public static BigInteger []f= new BigInteger [10000006  ]; 
    public static void preprocess2(){
        f[0] = BigInteger.ZERO ; 
        for (int i = 1;i<=MAXN;i++){
            BigInteger temp = BigInteger.valueOf(i)   ;
            temp = temp.multiply(temp);
            temp = temp.multiply(temp);
            f[i] = temp.add(f[i-1]);
        }
    }
    public static void otherSolution(){
        preprocess2();
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        BigInteger n,m;
        int t = cin.nextInt();
        while( t > 0 ){
            t = t -1 ;
            n = cin.nextBigInteger();
            m = cin.nextBigInteger();
            BigInteger ans = BigInteger.ZERO;
            if ( n.compareTo(BigInteger.valueOf(MAXN)) <= 0 ){
                int nn =  n.intValue();
                for(int i =1 ,next;i<=nn;i=next+1 ) {
                    int value = nn /i;
                    next = nn / (nn/i);
                    BigInteger temp = f[next].subtract(f[i-1]).multiply(BigInteger.valueOf(value));
                    ans = temp.add(ans).mod(m);
                }
                System.out.println(ans);
            }
            else {
                long nl= n.longValue();
                long ml= m.longValue();
                int len = 0;
                long [] nnext = new long [200005] ;
                long [] nvalue = new long [200005] ;
            
                for(long i =1 , next ; i <= nl  ; i= next +1 ){
                    next = nl / ( nl /i ) ;
                    nnext[len ] = next;
                    nvalue [len] = nl/i;
                    len = len +1;
                }
                long addLevel = 0 ;
                long level = 0;
                for(int i=len -1 ;i>=0 ;i--){
                    addLevel  = nvalue[i]  -level;
                    level =  level + addLevel ;
                    if( nnext[i] <= 1000000){
                        int temp = (int) nnext[i];
                        ans =(f[temp].multiply (BigInteger.valueOf(addLevel))).mod(m).add(ans).mod(m);
                    }
                    else 
                        ans =(Cal_S4_2(BigInteger.valueOf(nnext[i])).multiply (BigInteger.valueOf(addLevel))).mod(m).add(ans).mod(m);
                }
                System.out.println(ans);
            }
        }
    }
    public static void tempSolution(){
        preprocess2();
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        BigInteger n,m;
        int t = cin.nextInt();
        
        
        while( t > 0 ){
            t = t -1 ;
            n = cin.nextBigInteger();
            m = cin.nextBigInteger();
            BigInteger ans = BigInteger.ZERO;


            if ( n.compareTo(BigInteger.valueOf(MAXN)) <= 0 ){
                int nn =  n.intValue();
                for(int i =1 ,next;i<=nn;i=next+1 ) {
                    int value = nn /i;
                    next = nn / (nn/i);
                    BigInteger temp = f[next].subtract(f[i-1]).multiply(BigInteger.valueOf(value));
                    ans = temp.add(ans).mod(m);
                }
                System.out.println(ans);
            }
            else{
                BigInteger i ,next,value;
                i = BigInteger.ONE;
                BigInteger last = BigInteger.ZERO ;
                BigInteger cur = BigInteger.ZERO ;
            
                while ( i .compareTo( n ) <= 0 ) {
                    value = n.divide(i);
                    next = n.divide(value);
                    last = cur;
                    if( next.compareTo( BigInteger.valueOf(MAXN)) <= 0 ){
                        int nextInt = next.intValue();
                        if( nextInt <= MAXN ) 
                            cur = f[next.intValue()];
                        else 
                            cur = S4_2(next,m.intValue ());
                    }
                    else 
                        cur = S4_2(next, m.intValue());
                    BigInteger segment = (cur.subtract(last).add(m) ).mod(m);
                    ans = ans.add( segment.multiply(value.mod(m) ) ) .mod(m);
                    i = next.add(BigInteger.ONE);
                }
                System.out.println(ans);
            }
        }
        
    }
    public static void main(String []argv) {
        otherSolution();
    }
};
















