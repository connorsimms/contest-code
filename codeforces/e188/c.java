import java.io.*;
import java.util.*;
import java.math.*;

public class c
{
    public static void main(String[] args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        String T;
        try {
            T = br.readLine();
        } catch (Exception e)
        {
            return;
        }

        int t = Integer.parseInt(T);

        while (t-- > 0)
        {
            String l = "";
            try {
                l = br.readLine();
            } catch (Exception e) { return; }

            String[] inp = l.split(" ");

            BigInteger a = new BigInteger(inp[0]);
            BigInteger b = new BigInteger(inp[1]);
            BigInteger c = new BigInteger(inp[2]);
            BigInteger m = new BigInteger(inp[3]);

            BigInteger lcmAB = a.multiply(b).divide(a.gcd(b));
            BigInteger lcmBC = b.multiply(c).divide(b.gcd(c));
            BigInteger lcmAC = a.multiply(c).divide(a.gcd(c));
            BigInteger lcmABC = a.multiply(lcmBC).divide(a.gcd(lcmBC));

            BigInteger A = m.divide(a);
            BigInteger B = m.divide(b);
            BigInteger C = m.divide(c);

            BigInteger AB = m.divide(lcmAB);
            BigInteger BC = m.divide(lcmBC);
            BigInteger AC = m.divide(lcmAC);

            BigInteger ABC = m.divide(lcmABC);

            BigInteger x1 = BigInteger.valueOf(6);
            BigInteger x2 = BigInteger.valueOf(3);
            BigInteger x3 = BigInteger.valueOf(2);

            BigInteger ansA = A.multiply(x1).subtract(AB.multiply(x2)).subtract(AC.multiply(x2)).add(ABC.multiply(x3));
            BigInteger ansB = B.multiply(x1).subtract(AB.multiply(x2)).subtract(BC.multiply(x2)).add(ABC.multiply(x3));
            BigInteger ansC = C.multiply(x1).subtract(BC.multiply(x2)).subtract(AC.multiply(x2)).add(ABC.multiply(x3));

            pw.write(ansA.toString());
            pw.write(' ');
            pw.write(ansB.toString());
            pw.write(' ');
            pw.write(ansC.toString());
            pw.write('\n');
        }

        pw.close();
    }
}
