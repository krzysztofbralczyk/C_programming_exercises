#include <stdio.h>
#include <string.h>

struct file_t
{
    FILE* f;
    int size;
};

void chomp(char* s) {
    while (*s && *s != '\n') s++;
    *s = '\0';
}

int open_file(struct file_t* f, const char* filename) {
    if (f == NULL || filename == NULL) return 1;
    f->f = fopen(filename, "a");
    if (f->f == NULL) return 2;
    f->size = ftell(f->f);
    return 0;
}

void close_file(struct file_t* f) {
    if (f == NULL || f->f == NULL) return;
    fclose(f->f);
}

struct file_t* find_min(const struct file_t* files, int size) {
    if (files == NULL || size <= 0) return NULL;
    int min_size = files->size;
    int min_idx = 0;

    for (int i = 0; i < size; i++) {
        if ((files + i)->size < min_size) {
            min_size = (files + i)->size;
            min_idx = i;
        }
    }
    return (struct file_t*)(files + min_idx);
}




int main() {
    printf("Podaj nazwy plikow:");
    int files_to_open = 5;
    char filename[100] = { '\0' };
    FILE* check;
    struct file_t file1 = { NULL,0 };
    struct file_t file2 = { NULL,0 };
    struct file_t file3 = { NULL,0 };
    struct file_t file4 = { NULL,0 };
    struct file_t file5 = { NULL,0 };
    struct file_t files[5] = { file1,file2,file3,file4,file5 };
    int i = 0;

    fgets(filename, 100, stdin);
    while (strcmp(filename, "\n") != 0) {
        chomp(filename);
        check = fopen(filename, "r");
        if (check != NULL) {
            fclose(check);
            if (files_to_open > 0) open_file((files + i), filename);
            files_to_open--;
            i++;
        }
        fgets(filename, 100, stdin);
    }

    if (files_to_open == 5) {
        printf("Couldn't open file");
        return 4;
    }

    printf("Podaj teksty: ");
    char text[1000] = { '\0' };
    fgets(text, 1000, stdin);
    struct file_t* min;
    while (strcmp(text, "\n") != 0) {
        min = find_min(files, 5 - files_to_open);
        fputs(text, min->f);
        min->size = ftell(min->f);
        fgets(text, 1000, stdin);
    }

    for (int j = 0; j < 5 - files_to_open; j++) {
        close_file(files + j);
    }
    printf("Files saved");
    return 0;
}

