#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;

    int left = 0, right = numsSize - 1;

    // Find the starting position of target
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            if (mid == 0 || nums[mid - 1] < target) {
                result[0] = mid;
                break;
            }
            right = mid - 1;
        }
    }

    left = 0;
    right = numsSize - 1;

    // Find the ending position of target
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            if (mid == numsSize - 1 || nums[mid + 1] > target) {
                result[1] = mid;
                break;
            }
            left = mid + 1;
        }
    }

    return result;
}