import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = new int[3];
        arr[0]=1;
        arr[1]=2;
        arr[2]=3;
        ReverseArray rvrs = new ReverseArray();
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(rvrs.reverseArray(arr)));
    }
}
