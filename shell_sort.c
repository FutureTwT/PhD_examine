# include <stdio.h>
# include <stdlib.h>

void sort(int* arr, int arr_size) {
    // for each step
    for (int gap = arr_size/2; gap > 0; gap /= 2) {
        // for each sub-array
        for (int head = 0; head < gap; head ++) {
            for (int i = head+gap; i < arr_size; i += gap) {
                int key = arr[i];
                int j = i - gap;
                while (j >= head && arr[j] > key) {
                    arr[j+gap] = arr[j];
                    j -= gap;
                }
                arr[j+gap] = key;
            }
        }
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