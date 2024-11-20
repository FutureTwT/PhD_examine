# include <stdio.h>
# include <stdlib.h>

void sort(int* arr, int arr_size) {
    for (int i = 1; i < arr_size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[] = {2,5,3,8,7,12,0,1,5};
    int arr_size =  sizeof(arr) / sizeof(arr[0]);
    printf("Size: %d\n", arr_size);
    sort(arr, arr_size);
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}