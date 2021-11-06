int removeElement(int* nums, int numsSize, int val) {
    int p = 0, q = numsSize;
    while (p < q) {
        if (nums[p] == val) {
            nums[p] = nums[q - 1];
            q--;
        }
        else {
            p++;
        }
    }
    return p;
}
//
int removeElement(int* nums, int numsSize, int val) {
    int p = 0, q = 0;
    while (q < numsSize) {
        if (nums[q] != val) {
            nums[p] = nums[q];
            p++;
        }
        q++;
    }
    return p;
}