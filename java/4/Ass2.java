class Ass2 {
    public static void main(String[] args) {
        String res1 = "First Resource";
        String res2 = "Second Resource";
        
        //thread 1
        Thread t1 = new Thread() {
            public void run() {
                synchronized(res1) {
                    System.out.println("Locked the first resource");
                    try{Thread.sleep(100);} catch(Exception e) {}
                }

                synchronized (res2) {}
            }
        };

        // thread 2
        Thread t2 = new Thread() {
            public void run() {
                synchronized(res2) {
                    System.out.println("Locked the second Resource");
                    try{Thread.sleep(200);} catch(Exception e) {}
                }
                synchronized(res1) {}
            }
        };

        t1.start();
        t2.start();
    }
}