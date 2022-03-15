public class ReverseArray {

    int[] reverseArray(int[] arr) {

        int[] tmp = new int[arr.length];
        int j = arr.length-1;
        for (int i = 0; i < arr.length; i++) {

            tmp[i]=arr[j];
            j--;
        }
        return tmp;
    }
}
