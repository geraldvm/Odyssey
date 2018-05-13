package com.company;

public class QuickSort {

    private int partition(String arr[], int low, int high)
    {
        String pivot = arr[high];
        int i = (low-1);
        for (int j=low; j<high; j++)
        {
            if (arr[j].compareTo(pivot) <= 0)
            {
                i++;

                String temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

         String temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }


    public void sort(String arr[], int low, int high){
        sort_aux(arr,low,high);
    }
    private void sort_aux(String arr[], int low, int high)
    {
        if (low < high)
        {

            int pi = partition(arr, low, high);

            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
        }
    }


    public static void printArray(String arr[]){
        printArray_aux(arr);
    }
    private static void printArray_aux(String arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }


}
