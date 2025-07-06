//1. Buggy lines- Line 1: right = size + 1
//Line 3: left = mid

//2. why it is wrong -  Line 1 accesses out of bounds
//Line 3 may cause infinite loop

//3. fixes - Use right = size - 1 and left = mid + 1

//Corrected code
#include <stdio.h>

int binary_search(int nums[], int target, int size) {
    int left = 0, right = size-1;  // Line 1

    while (left <= right) {       // Line 2
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid+1;          // Line 3
        } else {
            right = mid - 1;     // Line 4
        }
    }
    return -1;
}

int main() {
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter the target to search: ");
    scanf("%d", &target);

    int index = binary_search(nums, target, n);

    printf("Index of %d is: %d\n", target, index);

    return 0;
}
