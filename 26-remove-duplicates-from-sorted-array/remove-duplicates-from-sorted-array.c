int removeDuplicates(int* nums, int numsSize) {
    int q = 0;
    for (int p = 0; p < numsSize; p++){
        if (nums[p] != nums[q]){
            q++;
            nums[q] = nums[p];
        }
    }
    return q + 1;
}