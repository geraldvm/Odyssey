package com.company;

//import static com.sun.org.apache.bcel.internal.classfile.Utility.printArray;

public class Main {

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

    public static void main(String[] args) {
        String arr[] = {"Juan", "Zelo", "Herman", "Fiorella", "Juana", "Elvira"};
        int n = arr.length;
        QuickSort ob = new QuickSort();
        ob.sort(arr, 0, n-1);
        System.out.println("QuickSort: sorted array");
        printArray(arr);

        BubbleSort f = new BubbleSort();
        String arry[] = {"Juana","Zelo","Juan"};
        f.sort(arry);
        System.out.println("BubbleSort");
        printArray(arry);

        RadixSort r = new RadixSort();
        String arrR[] = {"Esteban","Diana","Alejandro","Pablo"};
        int rr = arrR.length;
        r.sort(arrR, rr+1);
        System.out.println("RadixSort");
        printArray(arrR);


    }
}
