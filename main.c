#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>       
#include <dirent.h>   
#include <conio.h>

char* get_path(char *string) { 
    char *path = malloc(sizeof(char) * (strlen(string) + 2)); 
     if (path != NULL) {
        path[0] = '\0';  
        strcat(path, string); 
        strcat(path, "\\"); 
        printf("[INFO] The path has been introduced: %s\n", path);  
    }
    return path; 
}

char* trimSpaces(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }
    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t')) {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

int directoryExists(const char *path) {
    if (_access(path, 0) == 0) {
        return 1; 
    }
    return 0; 
}

void listFiles(const char *path) {
    char searchPath[260];
    struct _finddata_t fileData;
    intptr_t handle;
    snprintf(searchPath, sizeof(searchPath), "%s*", path); 
    handle = _findfirst(searchPath, &fileData);
    if (handle == -1) {
        printf("[ERROR] Could not open directory: %s\n", path);
        return;
    }
    printf("Files in directory %s:\n", path);
    do {
        printf("- %s\n", fileData.name);
    } while (_findnext(handle, &fileData) == 0);

    _findclose(handle); 
}

#include <stdio.h>
#include <string.h>
#include <errno.h>

void createFile(const char *path, const char *filename) {
    char fullPath[260];
    char fullFilename[260] = "";
    char textInsert[1024] = ""; 

    if (!path || !filename) {
        printf("[ERROR] Path or filename is NULL\n");
        return;
    }
    
    if (snprintf(fullFilename, sizeof(fullFilename), "%s.txt", filename) >= (int)sizeof(fullFilename)) {
        printf("[ERROR] Filename is too long\n");
        return;
    }

    if (snprintf(fullPath, sizeof(fullPath), "%s/%s", path, fullFilename) >= (int)sizeof(fullPath)) {
        printf("[ERROR] Path is too long\n");
        return;
    }

    FILE *file = fopen(fullPath, "w");
    if (!file) {
        printf("[ERROR] Could not create file: %s (Error: %s)\n", 
               fullPath, strerror(errno));
        return;
    }
    
    printf("[INFO] File created successfully: %s\n", fullPath);
    printf("[INFO] The full path of the file: %s\n", fullPath);

    printf("Enter the text to write into the file (press Enter to finish):\n");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (fgets(textInsert, sizeof(textInsert), stdin)) {
        size_t len = strlen(textInsert);
        if (len > 0 && textInsert[len-1] == '\n') {
            textInsert[len-1] = '\0';
        }

        if (fprintf(file, "%s", textInsert) < 0) {
            printf("[ERROR] Failed to write to file\n");
        } else {
            printf("[INFO] Text written to file successfully.\n");
        }
    } else {
        printf("[ERROR] Failed to read input\n");
    }
    
    fclose(file);
}

void deleteFile(const char *path, const char *filename) {
    char fullPath[260];
    snprintf(fullPath, sizeof(fullPath), "%s%s", path, filename);
    if (remove(fullPath) == 0) {
        printf("[INFO] File deleted successfully: %s\n", fullPath);
    } else {
        printf("[ERROR] Could not delete file: %s\n", fullPath);
    }
}

int main() {
    int choice;
    char path[255] = "";
    char filename[255] = "";
    printf("Enter the path you want to work in: ");
    fgets(path, sizeof(path), stdin);   
    path[strcspn(path, "\n")] = '\0'; 
    char *trimmedPath = trimSpaces(path);
    char *fullPath = get_path(trimmedPath);
    if (fullPath == NULL) {
        printf("[ERROR] Failed to get path\n");
        return 1;
    }
    if (!directoryExists(fullPath)) {
        printf("[ERROR] The specified path does not exist: %s\n", fullPath);
        free(fullPath); 
        return 1;
    }
    do {
        printf("\nMenu:\n");
        printf("1. List files\n");
        printf("2. Create a file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                listFiles(fullPath);
                break;
            case 2:
                printf("Enter the name of the file to create: ");
                scanf("%255s", filename);
                createFile(fullPath, filename);
                break;
            case 3:
                printf("Enter the name of the file to delete: ");
                scanf("%255s", filename);
                deleteFile(fullPath, filename);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("[ERROR] Invalid option. Please try again.\n");
        }
    } while (choice != 4);
    free(fullPath);
    return 0;
}
