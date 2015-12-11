/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* r = (int *) malloc(sizeof(int) * (numsSize));
    long production = 1;
    int i, zero = 0, idx;
    *returnSize = numsSize;
    
    for(i = 0; i < *returnSize; i++) {
        r[i] = 0;
    }
    
    for(i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            production *= nums[i];
        } else {
            idx = i;
            zero++;
        }
    }
    
    if(zero > 1) {
        return r;
    } else if(zero == 1) {
        r[idx] = production;
        return r;
    }
    
    for(i = 0; i < *returnSize; i++) {
        r[i] = production/nums[i];
    }
    
    return r;
}
