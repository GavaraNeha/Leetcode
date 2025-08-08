int maxArea(int* height, int heightSize) {
    int max_area = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        // Determine the shorter line to calculate the area
        int current_height;
        if (height[left] < height[right]) {
            current_height = height[left];
        } else {
            current_height = height[right];
        }

        int width = right - left;
        int current_area = current_height * width;

        // Update the maximum area if the current area is larger
        if (current_area > max_area) {
            max_area = current_area;
        }

        // Move the pointer of the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_area;
}