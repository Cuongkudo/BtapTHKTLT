#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(const char *filename, char *content) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Khong the mo file %s\n", filename);
        exit(1);
    }

    char line[1024];
    content[0] = '\0';
    while (fgets(line, sizeof(line), file)) {
        strcat(content, line);
    }
    fclose(file);
}


void remove_comments(const char *input, char *output) {
    int in_comment = 0;
    int in_line_comment = 0;
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (in_comment) {
            if (input[i] == '*' && input[i + 1] == '/') {
                in_comment = 0;
                i++; 
            }
        } else if (in_line_comment) {
            if (input[i] == '\n') {
                in_line_comment = 0;
                output[j++] = input[i];
            }
        } else {
            if (input[i] == '/' && input[i + 1] == '*') {
                in_comment = 1;
                i++; 
            } else if (input[i] == '/' && input[i + 1] == '/') {
                in_line_comment = 1;
                i++; 
            } else {
                output[j++] = input[i];
            }
        }
    }
    output[j] = '\0';
}


void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Khong the mo file %s\n", filename);
        exit(1);
    }
    fprintf(file, "%s", content);
    fclose(file);
}

int main() {
    char input_file[256], output_file[256];
    char content[100000], cleaned_content[100000];

    
    printf("Nhap ten file dau vao: ");
    scanf("%s", input_file);
    printf("Nhap ten file dau ra: ");
    scanf("%s", output_file);

    
    read_file(input_file, content);
    remove_comments(content, cleaned_content);
    write_file(output_file, cleaned_content);

    printf("Da xoa chu thich va luu vao file %s\n", output_file);
    return 0;
}
