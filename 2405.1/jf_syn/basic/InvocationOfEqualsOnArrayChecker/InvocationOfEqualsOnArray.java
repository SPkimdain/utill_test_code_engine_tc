package basic;

public class InvocationOfEqualsOnArray {
    public void test() {
        int [] a = new int[3];
        int [] b = new int[3];
        for (int i = 0; i < a.length; i++) {
            a[i] = i * 3;
            b[i] = i + 2;
        }

        if (a.equals(b)) { // @violation
            System.out.println("a == b");
        }
    }
}