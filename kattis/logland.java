import java.util.Scanner;
import java.util.ArrayList;
import java.math.BigInteger;

public class logland
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();

        ArrayList<BigInteger> v = new ArrayList<>();
        ArrayList<BigInteger> s = new ArrayList<>();

        BigInteger x = sc.nextBigInteger();
        v.add(x);
        s.add(BigInteger.ONE.shiftLeft(0).multiply(x));

        for (int i = 1; i < k; ++i)
        {
            x = sc.nextBigInteger();
            v.add(x);
            s.add(s.get(i - 1).add(BigInteger.ONE.shiftLeft(i).multiply(x)));
        }

        BigInteger leftBehind = BigInteger.ZERO;
        BigInteger gap = BigInteger.ZERO;

        for (int i = k - 1; i >= 0; --i)
        {
            if (v.get(i).compareTo(gap) >= 0)
            {
                v.set(i, v.get(i).subtract(gap));
                gap = BigInteger.ZERO;
            }

            if (v.get(i).testBit(0))
            {
                
            }
        }
    }
}
