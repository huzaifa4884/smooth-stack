

class SingletonLocked {
    private static volatile SingletonLocked instance;
    public static SingletonLocked getInstance() {
        if (instance == null) {
            synchronized(SingletonLocked.class) {
                System.out.print("locked auired by thread  ");
                System.out.println(Thread.currentThread().getId());
                if(instance == null) {
                    System.out.println("instance created(or initlized");
                    instance = new SingletonLocked();
                }
            }
        }
        else {
            System.out.println("instance already created");
        }
        return instance;
    }
    
}


public class Ass1 {
    public static void main(String[] args) {
        Thread t1 = new Thread() {
            public void run() {
                SingletonLocked inst = SingletonLocked.getInstance();
            }
        };
    
        Thread t2 = new Thread() {
            public void run() {
                SingletonLocked inst1 = SingletonLocked.getInstance();
            }
        };

        t1.start();
        t2.start();
        
    }
    
}
