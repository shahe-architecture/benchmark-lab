#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "semiring.h"


const char *filename = "workloads/semiring/case1.data";
const int case_size = 512; /* 512x512x512 */

float elapsed_semiring_time() {
    int fd;
    struct stat buf;
    void *mapped;

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open failed");
        exit(1);
    }

    if (fstat(fd, &buf) == -1) {
        perror("fstat failed");
        close(fd);
        exit(1);
    }

    mapped = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap failed");
        close(fd);
        exit(1);
    }
    close(fd);
    int32_t *array1 = (int32_t *)mapped;
    int32_t *array2 = array1 + case_size * case_size;
    int32_t *array3 = array2 + case_size * case_size;

    clock_t start, end;
    start = clock();
    semiring_func(array1, array2, array3, case_size);
    end = clock();
    float time_spent = (float)(end - start) / CLOCKS_PER_SEC;
    if (munmap(mapped, buf.st_size) == -1) {
        perror("munmap failed");
        exit(1);
    }

    return case_size*case_size*case_size/time_spent;
}
