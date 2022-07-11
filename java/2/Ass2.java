

public class Ass2 {

    static int row;
    static int culomn;

    private static int random()
    {
        return (int) (Math.random() * (99)+1);
    }
    
    private static int max(int[][] arr){
        int max = arr[0][0];

        for (int i = 0; i<row; i++){

            for(int j = 0; j<culomn; j++){

                if (max < arr[i][j])
                {
                    max = arr[i][j];
                }
            }
        }
        return max;
    }
    public static void main(String args[]){
        row = 4;
        culomn = 4;

        int[][] arr = new int[row][culomn];

        for (int i=0; i<row; i++){

            for(int j=0; j<culomn; j++){

                arr[i][j] = random();
                System.out.print(arr[i][j]);
                System.out.print("  ");
            }
            System.out.println();
        }

        System.out.println(max(arr));

    }
    
}
