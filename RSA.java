import java.math.*;
import java.util.*;

class RSA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int p, q, n, phi, d = 0, e, i;
        System.out.print("Enter the number to be encrypted and decrypted: ");
        int msg = sc.nextInt();
        double c;
        BigInteger msgback;
        System.out.print("Enter 1st prime number p: ");
        p = sc.nextInt();
        System.out.print("Enter 2nd prime number q: ");
        q = sc.nextInt();

        n = p * q;
        phi = (p - 1) * (q - 1);
        System.out.println("The value of phi = " + phi);

        for (e = 2; e < phi; e++) {
            if (gcd(e, phi) == 1) break;
        }
        System.out.println("The value of e = " + e);
        for (i = 0; i <= 9; i++) {
            int x = 1 + (i * phi);
            if (x % e == 0)      //d is for private key exponent
            {
                d = x / e;
                break;
            }
        }
        System.out.println("The value of d = " + d);
        c = (Math.pow(msg, e)) % n;
        System.out.print("Encrypted message is : ");
        System.out.println(c);
        //converting int value of n to BigInteger
        BigInteger N = BigInteger.valueOf(n);
        //converting float value of c to BigInteger
        BigInteger C = BigDecimal.valueOf(c).toBigInteger();
        msgback = (C.pow(d)).mod(N);
        System.out.print("Decrypted message is : ");
        System.out.println(msgback);

    }

    static int gcd(int e, int z) {
        if (e == 0)
            return z;
        else
            return gcd(z % e, e);
    }
}