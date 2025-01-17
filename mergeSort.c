#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int low,int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int size = high - low + 1;
    int *tarr = (int*) malloc ( size *sizeof(int));
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            tarr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            tarr[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        tarr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        tarr[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0; i < size; i++)
    {
        arr[low + i] = tarr[i];
    }
}

void mergeSort(int arr[],int low,int high){
    if (low<high)
    {
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr,low,mid,high);
        
    }
    
}
int main(){
    int arr[] = {1, 2, 11, 5, 4,9,8,7,10,6,3};
    
    int n =  sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    printf("after sorting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}