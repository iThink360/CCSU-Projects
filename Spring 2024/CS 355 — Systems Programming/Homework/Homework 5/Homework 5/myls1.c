//
//  myls1.c
//  Homework 5
//
//  Created by Rumman Shahzad on 3/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function prototypes
int compare(const void *, const void *);
void ls(const char *, int, int);

int main(int argc, const char * argv[]) {
    
    // Arguments to pass to ls() function invocation
    const char *dir = ".";
    int showHidden = 0;
    int sort = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            showHidden = 1; // Show hidden files
        }
        else if (strcmp(argv[i], "-s") == 0) {
            sort = 1; // Sort files in lexicographical order
        }
        else if (strcmp(argv[i], "-r") == 0) {
            sort = -1; // Sort in reverse lexicographical order
        }
        else {
            dir = argv[i];
        }
    }
    
    // Invoke ls()
    ls(dir, showHidden, sort);
    return 0;
}

// Comparison function for qsort() to sort strings.
int compare(const void * a, const void * b) {
    return strcmp(*(const char**) a, *(const char**) b);
}

// Driver function for ls command, listing entries in a directory as commanded by arguments.
void ls(const char * dirname, int showHidden, int sort) {
    
    // Setup pointers and variables for capturing entry information
    DIR *dirPtr;
    struct dirent *entry;
    int maxEntries = 1000;
    int numEntries = 0;
    
    // Allocate enough memory for directory entries
    char **files = (char**) malloc(maxEntries * sizeof(char*));
    
    // If memory allocation failed, exit
    if (files == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }
    
    // Only output directory entries if directory successfully opens
    if ((dirPtr = opendir(dirname)) == NULL) {
        fprintf(stderr, "myls1: Cannot open %s\n", dirname);
    }
    else {
        
        // Start allocating the directory entries according to specifications
        
        // Show hidden files only if specified
        while ((entry = readdir(dirPtr)) != NULL) {
            if(showHidden == 1 || entry->d_name[0] != '.') {
                files[numEntries] = strdup(entry->d_name);
                numEntries++;
            }
        }
        closedir(dirPtr);
        
        // Sort the files if needed
        if (numEntries > 0 && sort != 0) {
            qsort(files, numEntries, sizeof(char*), compare);
        }
        
        // Reverse the sorted files if needed
        if (sort == -1) {
            for (int i = 0, j = numEntries-1; i < j; i++, j--) {
                char *temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
        
        // Print the final configured list of files, freeing them from memory one by one
        for (int i = 0; i < numEntries; i++) {
            printf("%s\n", files[i]);
            free(files[i]);
        }
    }
    
    // Free the allocated memory pointer altogether
    free(files);
}

