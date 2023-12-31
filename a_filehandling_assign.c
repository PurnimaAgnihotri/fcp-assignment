#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[100];
} Person;

unsigned long checksum(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    unsigned long sum = 0;
    int c;
    while ((c = getc(file)) != EOF) 
    {
     sum += c;
    }
fclose(file);
    return sum;
}

int main() {
    FILE *file;
    Person person = {1, "Purnima Agnihotri"};

    file = fopen("data.txt", "w");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "Hi,I'm Purnima Agnihotri of ECE-A(52)\n");

    fprintf(file, "Person ID: %d, Name: %s\n", person.id, person.name);

    fclose(file);

    unsigned long fileChecksum = checksum("data.txt");

    file = fopen("data.txt", "a");
    if (!file) {
        perror("error opening file");
        return 1;
    }
    fprintf(file, "checksum: %lu\n", fileChecksum);

    for (int i = 2; i <= 50; ++i) {
        fprintf(file, "multiplication table of %d:\n", i);
        for (int j = 1; j <= 10; ++j) {
            fprintf(file, "%d x %d = %d\n", i, j, i * j);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    
}
