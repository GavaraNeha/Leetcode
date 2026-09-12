class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // We are going down, so a peak is at mid or to the left
                right = mid;
            } else {
                // We are going up, so a peak is to the right
                left = mid + 1;
            }
        }

        return left;
    }
}