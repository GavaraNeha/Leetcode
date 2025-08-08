double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to optimize the binary search range
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int total_length = m + n;
    int half_total = (total_length + 1) / 2;

    int low = 0;
    int high = m;

    while (low <= high) {
        int i = low + (high - low) / 2;
        int j = half_total - i;

        // Get the four boundary elements for comparison
        int nums1_left = (i == 0) ? -2000000 : nums1[i - 1];
        int nums1_right = (i == m) ? 2000000 : nums1[i];
        int nums2_left = (j == 0) ? -2000000 : nums2[j - 1];
        int nums2_right = (j == n) ? 2000000 : nums2[j];

        if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
            // We've found the perfect partition
            if (total_length % 2 == 1) {
                // Odd length, median is the largest element of the left half
                return (double)fmax(nums1_left, nums2_left);
            } else {
                // Even length, median is the average of max_left and min_right
                int max_left = fmax(nums1_left, nums2_left);
                int min_right = fmin(nums1_right, nums2_right);
                return (double)(max_left + min_right) / 2.0;
            }
        } else if (nums1_left > nums2_right) {
            // Partition in nums1 is too far to the right, move it left
            high = i - 1;
        } else { // nums2_left > nums1_right
            // Partition in nums1 is too far to the left, move it right
            low = i + 1;
        }
    }

    return 0.0; // Should not be reached with valid inputs
}