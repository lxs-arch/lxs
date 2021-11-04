int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int p = 1, q = 1;
    while (q < numsSize) {
        if (nums[q] != nums[q - 1]) {
            nums[p] = nums[q];
            p++;
        }
        q++;
    }
    return p;
}