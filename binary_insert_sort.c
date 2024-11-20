# include <stdio.h>
# include <stdlib.h>

void sort(int* arr, int arr_size) {
    int key, left, right, mid;
    for (int i = 1; i < arr_size; i++) {
        left = 0;
        right = i - 1;
        key = arr[i];
        while (left <= right) {
            mid = (left + right) / 2;
            if (key < arr[mid]) {
                right = mid - 1;
            } else { // key = arr[mid] or key > arr[mid]
                left = mid + 1; 
            }
        }
        for (int j = i-1; j >= right+1; j--) {
            arr[j+1] = arr[j];
        }
        arr[right+1] = key;
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