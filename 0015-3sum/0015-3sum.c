#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Sort the array to use the two-pointer approach and easily handle duplicates
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 100; // Initial capacity, will reallocate as needed
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate values for the first number to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                // Found a valid triplet
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                int* triplet = (int*)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Move pointers and skip duplicates for the second and third numbers
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }

            } else if (sum < target) {
                left++;
            } else { // sum > target
                right--;
            }
        }
    }

    // Resize to exact size before returning
    if (*returnSize > 0) {
        result = (int**)realloc(result, (*returnSize) * sizeof(int*));
        *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));
    } else {
        free(result);
        free(*returnColumnSizes);
        result = NULL;
        *returnColumnSizes = NULL;
    }

    return result;
}