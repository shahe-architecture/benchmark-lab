#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    int NUM_ELEMENTS = 1024;
    int MAX_VALUE = 1024;
    srand(42);

    if (argc > 1) {
        assert(argc == 3);
        NUM_ELEMENTS = atoi(argv[1]);
        MAX_VALUE = atoi(argv[2]);
    }

    FILE *file = fopen("data.bin", "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int random_number = rand() % MAX_VALUE;
        fwrite(&random_number, sizeof(int), 1, file);
    }

    fclose(file);

    printf("Random numbers have been written to data.bin.\n");

    return 0;
}
