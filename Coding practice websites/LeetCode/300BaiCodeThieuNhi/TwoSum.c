#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (*(nums + i) + *(nums + j) == target)
            {
                *returnSize = i;
                *(returnSize + 1) = j;
            }
        }
    }
    return returnSize;
}

void main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize[2];
    int size = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", *(twoSum(nums, size, target, returnSize) + i));
    }
}