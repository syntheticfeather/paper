package thread;

public class ThreadTest {

    public static void main(String[] args) {
        recThreadTest();
    }

    public static void recThreadTest() {
        System.out.println("+----------+");
        System.out.println("|ThreadTest|");
        System.out.println("+----------+");

        /*
         * 现在我们要打印一个矩形
         * 不过呢有-, +, |三种形式的符号
         * 我们打算有个随机样
         */
        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 5; i++) {
                    System.err.println("-----");
                }

            }
        });
        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 5; i++) {
                    System.err.println("|   |");
                }
            }
        });
        Thread t3 = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 5; i++) {
                    System.err.println("+++++");
                }
            }
        });
        t1.start();
        t2.start();
        t3.start();
    }
}
