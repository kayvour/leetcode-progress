#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b); // Fixed: Added closing parenthesis
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 100000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100000);
    *returnSize = 0;

    if (numsSize < 3) {
        return result;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; // Skip duplicates for the first element
        }

        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            // Reduced output
            // printf("Checking triplet: [%d, %d, %d] => sum: %d\n", nums[i], nums[left], nums[right], sum);

            if (sum == 0) {
                if (*returnSize >= 100000) {
                    break; // Prevent exceeding allocated size
                }

                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Print only a summary of found triplets
                if (*returnSize <= 10) { // Print only the first 10 triplets found
                    printf("Found triplet: [%d, %d, %d]\n", nums[i], nums[left], nums[right]);
                }

                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    // Debug: Print total triplets found
    printf("Total triplets found: %d\n", *returnSize);
    // Print only the first 10 triplets for summary
    for (int i = 0; i < *returnSize && i < 10; i++) {
        printf("Triplet %d: [%d, %d, %d]\n", i, result[i][0], result[i][1], result[i][2]);
    }

    return result;
}