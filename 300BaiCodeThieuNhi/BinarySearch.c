#include <stdio.h>
int search(int *nums, int numsSize, int target)
{
    int result;
    for (int i = 0; i < numsSize; i++)
    {
        if (*(nums + i) == target)
        {
            return i;
        }
        else
            continue;
    }
    return -1;
}
void main()
{
    int nums[] = {-1, 0, 3, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 10;
    printf("%d", search(nums, size, target));
}