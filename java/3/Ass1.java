import java.io.File;

class Ass1 {
    public static void main(String args[])
    {
        // File folder = new File("../");
        // File[] listOfFiles = folder.listFiles();

        // for(int i = 0; i < listOfFiles.length; i++) {
            
        //     if(listOfFiles[i].isFile()) {
        //         System.out.println("File" + listOfFiles[i].getName());
        //     }

        //     else if (listOfFiles[i].isDirectory()) {
        //         System.out.println("Directory" + listOfFiles[i].getName());
        //     }
        // }
            walkin(new File("../"));

    }

    private static void walkin(File dir) {

        File[] listOfFiles = dir.listFiles();
        for(int i = 0; i < listOfFiles.length; i++) {

            if(listOfFiles[i].isDirectory()) {
                System.out.println("|\t\t" + listOfFiles[i].getName().toString());
                walkin(listOfFiles[i]);
            }
            else {
                System.out.println("+------" + listOfFiles[i].getName().toString());
            }
        }


    }
}