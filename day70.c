#include <stdio.h>

int maxLenZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Simple hash map using arrays (for simplicity)
    // Assume sum range is manageable
    int map[1000];
    for(int i = 0; i < 1000; i++) map[i] = -2; // -2 means not visited

    map[0 + 500] = -1; // handle sum = 0 case (offset to avoid negative index)

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(map[sum + 500] != -2) {
            int len = i - map[sum + 500];
            if(len > maxLen)
                maxLen = len;
        } else {
            map[sum + 500] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSumSubarray(arr, n));
    return 0;
}