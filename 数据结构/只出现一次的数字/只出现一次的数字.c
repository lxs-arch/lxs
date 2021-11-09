int singleNumber(int* nums, int numsSize) {
    int t = 0;
    for (int i = 0; i < numsSize; i++) {
        t ^= nums[i];
    }

    return t;
}