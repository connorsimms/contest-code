import java.util.Scanner;
import java.util.ArrayList;
import java.math.BigInteger;

class P {

    public P(String name, BigInteger bid) 
    {
        this.name = name;
        this.bid = bid;
    }

    public String name;
    public BigInteger bid;
}

public class intergalacticbidding {

    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);    

        int n = sc.nextInt();
        BigInteger s = sc.nextBigInteger();

        ArrayList<P> arr = new ArrayList<>();

        for (int i = 0; i < n; ++i)
        {
            String name = sc.next();
            BigInteger bid = sc.nextBigInteger();

            arr.add(new P(name, bid));
        }

        arr.sort((o1, o2) -> o1.bid.compareTo(o2.bid));

        int cnt = 0;
        ArrayList<String> ans = new ArrayList<>();

        for (int i = n - 1; i >= 0; --i)
        {
            P curr = arr.get(i);
            if (curr.bid.compareTo(s) <= 0)
            {
                ++cnt;
                ans.add(curr.name);
                s = s.subtract(curr.bid);
            }
        }

        if (s.equals(BigInteger.ZERO))
        {
            System.out.println(cnt);
            for (String name : ans)
                System.out.println(name);
        }
        else
        {
            System.out.println("0\n");
        }
    }
}
