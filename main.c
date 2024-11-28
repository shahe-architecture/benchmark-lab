#include <stdio.h>
#include "workloads/workloads.h"

int main() {
    float semiring_tops = elapsed_semiring_time();
    printf("semiring score: %f\n", semiring_tops/SEMIRING_BASELINE);
    return 0;
}