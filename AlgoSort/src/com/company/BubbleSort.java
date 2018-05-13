package com.company;

public class BubbleSort<T extends Comparable>
{
    public void sort(T arr[]){
        sort_aux(arr);
    }
    private void sort_aux(T arr[]) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    // swap temp and arr[i]
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

}