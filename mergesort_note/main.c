//
//  main.c
//  mergesort_note
//
//  Created by wu on 2024/6/17.
//

#include <stdio.h>

// 合併兩個子陣列的函數
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;  // 左子陣列的大小
    int n2 = r - q;      // 右子陣列的大小

    // 創建臨時陣列來存放左右子陣列的內容
    int L[n1], R[n2];
    int i, j, k;

    // 複製資料到臨時左子陣列 L[]
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];

    // 複製資料到臨時右子陣列 R[]
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // 合併左右子陣列到原始陣列 arr[]
    i = 0; // 初始化左子陣列的索引
    j = 0; // 初始化右子陣列的索引
    k = p; // 初始化合併後陣列的索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 將剩餘的元素複製到 arr[]，如果還有的話
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 合併排序的遞迴函數
void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  // 中間索引
        mergeSort(arr, p, q);      // 遞迴排序左子陣列
        mergeSort(arr, q + 1, r);  // 遞迴排序右子陣列
        merge(arr, p, q, r);       // 合併排序兩個子陣列
    }
}

// 輸出陣列的函數
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 主函數
int main() {
    int arr[] = {5,5,5,5,5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("原始陣列：\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("排序後的陣列：\n");
    printArray(arr, arr_size);

    return 0;
}
