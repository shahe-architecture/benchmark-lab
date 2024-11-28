#include "semiring.h"

static inline int32_t t_max(int32_t a, int32_t b) {
    return a > b ? a : b;
}

static inline int32_t t_min(int32_t a, int32_t b) {
    return a < b ? a : b;
}

void semiring_func(int32_t *array1, int32_t *array2, int32_t *array3, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                int case_type = k % 5;
                switch (case_type) {
                case 0:
                    array3[i * size + j] = array3[i * size + j] + array1[i * size + k] * array2[k * size + j];
                    break;
                case 1:
                    array3[i * size + j] = t_max(array3[i * size + j], array1[i * size + k] + array2[k * size + j]);
                    break;
                case 2:
                    array3[i * size + j] = t_max(array3[i * size + j], t_min(array1[i * size + k], array2[k * size + j]));
                    break;
                case 3:
                    array3[i * size + j] = t_min(array3[i * size + j], array1[i * size + k] * array2[k * size + j]);
                    break;
                case 4:
                    array3[i * size + j] = array3[i * size + j] & (array1[i * size + k] | array2[k * size + j]);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

