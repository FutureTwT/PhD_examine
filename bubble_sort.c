# include <stdio.h>
# include <stdlib.h>

void sort(int* arr, int arr_size) {
    for (int i = arr_size-1; i >= 0; i--) {
        
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