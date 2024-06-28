public class Search {
    public static int search(int arr[], int x)
    {
        int n = arr.length;
        // Traverse array arr[]
        for (int i = 0; i < n; i++) {
            // If element found then return that index
            if (arr[i] == x)
                return i;
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        // Element to search
        int x = 4;
        int result = search(arr, x);
        if (result == -1)
            System.out.print("Element is not present in array");
        else
            System.out.print("Element is present  at index " + result);
    }
}