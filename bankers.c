#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 5, m = 3;
    int alloc[5][3] = {{0, 1, 0}, 
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1}, 
    {0, 0, 2}};
    int max[5][3] = {{7, 5, 3}, 
    {3, 2, 2}, 
    {9, 0, 2}, 
    {2, 2, 2}, 
    {4, 3, 3}};
    int avail[3] = {3, 3, 2};
    bool finish[5] = {false};
    int ans[5];
    int ind = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (max[i][j] - alloc[i][j] > avail[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    ans[ind++] = i;
                    finish[i] = true;
                }
            }
        }
    }

    printf("Safe Sequence: ");
    for (int i = 0; i < n - 1; i++) {
        printf("P%d -> ", ans[i]);
    }
    printf("P%d\n", ans[n - 1]);

    return 0;
}
