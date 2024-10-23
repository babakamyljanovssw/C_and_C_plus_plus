#include <stdio.h>
#include <limits.h>

// O(n) time complexity
int maxSubArraySum(int arr[], int size) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}


// typedef struct node *node_ptr;

// struct node {
//     int data;
//     node_ptr next;
// };

// typedef node_ptr LIST;
// typedef node_ptr POSITION;

// int is_empty(LIST L) {
//     return L == NULL || L->next == NULL;
// }

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, n);
    printf("Maximum contiguous sum is %d\n", max_sum);


    // LIST L = NULL;

    // bool p = is_empty(L);

    // if (p) {
    //     printf("List is empty\n");
    // } else {
    //     printf("List is not empty\n");
    // }
    return 0;
}