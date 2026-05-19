// Online C compiler to run C program online
#include <stdio.h>

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int x = 0, y = 0;
    while(x < nums1Size && y < nums2Size){
        if(nums1[x] == nums2[y]){
            return nums1[x];
            x += 1;
            y += 1;
            printf("trace: nums1[%d] = %d, nums2[%d] = %d\n ", x, nums1[x], y, nums2[y]);
        }else if(nums1[x] < nums2[y]){
            x += 1;
            printf("trace: nums1[%d] = %d, nums2[%d] = %d\n ", x, nums1[x], y, nums2[y]);
        }else{
            y += 1;
            printf("trace: nums1[%d] = %d, nums2[%d] = %d\n ", x, nums1[x], y, nums2[y]);
        }
    }
    
    return -1;
}


int main() {
    int num1[] = {2,3,5,6,7};
    int num2[] = {5,7,8,5,3};
    int num1size = sizeof(num1)/sizeof(num1[0]);
    int num2size = sizeof(num2)/sizeof(num2[0]);
    int output;
    
    output = getCommon(num1, num1size,num2, num2size);
    
    printf("Common: %d\n", output);
    
    return 0;
}