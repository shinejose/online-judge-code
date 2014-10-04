import java.io.*;
import java.util.*;
import java.math.*;


class FACTORIZ{

    public static   int MAXN = 100000000;
    public static int MAXP = 50847534 + 5 ;
    public static int MAXP8 = 5761455 +500 ;
    public static boolean []isprime = new boolean [MAXN +5];
    public static int []  prime = new  int [MAXP];
    public static int primenum;
    public static void create_prime(int n) 
        {
            for(int i=2;i<=n;i++){
                if(!isprime[i])
                    prime[primenum++]=i;
                for(int j=0; j<primenum && i*prime[j]<=n;j++) 
                {
                    isprime[i*prime[j]]=true; //删去 （当前这个数×小于等于+其最小素因子）的数
                    if(i%prime[j]==0)  // 也就是每个合数可以划分成一个最小素因子和另一个数
                        break;      // 一个是另一个数×最小素因子来删除这个合数的
                }                // 不能找到第二种删除方法也就是说每个合数只能被删除1次
            }
        }



    public static void solution(){
        create_prime(MAXN);
        int t;
        Scanner cin  = new Scanner ( new BufferedInputStream(System.in));
        t = cin .nextInt();
        while (t > 0){
            t = t- 1 ;
            BigInteger n;
            n = cin .nextBigInteger ();

            int ansLen = 0;
            long [] ans = new long [MAXP ] ;
            long [] cnt = new long [MAXP] ;
            
            if( n .compareTo(new BigInteger("10000000000000000")) <= 0 ){
                long nl = n.longValue();
                for(int i=0;i<primenum;i++){
                    if ( nl % prime[i] == 0 ) {
                        ans[ansLen] = prime[i];
                        cnt[ansLen] = 0 ;
                        ansLen = ansLen +1 ;
                    }
                    while( nl % prime[i]  == 0){
                        nl  = nl / prime[i] ;
                        cnt[ansLen] ++ ;
                    }
                }
                if(  nl > 1){
                    ans[ansLen] = nl;
                    cnt[ansLen] =  1;
                    ansLen = ansLen +1;
                }

                int realAns = 0;
                for(int i=0;i<ansLen;i++){
                    realAns += cnt[i];
                }
                
                System.out.println(realAns);
                for(int i=0;i<ansLen;i++){
                    for( int j =0;j<cnt[i];j++)
                        System.out.println(ans[i]);
                }
            }
            else {
                System.out.println(1);
                System.out.println(n);
            }
        }
    }
    
    
    public static void main(String [] args ) {
        solution();
    }
}











