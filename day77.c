#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // If no element >= x

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1; // Search left half
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;  // If no element > x

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1; // Search left half
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target
    scanf("%d", &x);

    // Output lower and upper bound indices
    printf("%d %d", lowerBound(arr, n, x), upperBound(arr, n, x));

    return 0;
}