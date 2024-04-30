//
//  main.c
//  Homework 6
//
//  Created by Rumman Shahzad on 3/21/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, const char * argv[]) {
    
    // If argv[1] is not R, W, or RW, exit
    if (strcmp(argv[1], "R") != 0 && strcmp(argv[1], "W") != 0 && strcmp(argv[1], "RW") != 0) {
        perror("Invalid argument passed. Only use R, W, or RW.");
        return 1;
    }
    
    // Open the specified file, exit if there's an error
    int fd = open("./Screenshot.png", strcmp(argv[1], "R") ? O_RDONLY : (strcmp(argv[1], "W")) ? O_WRONLY : O_RDWR);
    if (fd < 0) {
        perror("Error opening the file.");
        return 1;
    }
    
    // Retrieve file stat
    struct stat file_stat;
    int ret = fstat(fd, &file_stat);
    
    // If there was an error getting file stat, exit
    if (ret < 0) {
        perror("Error getting the file stat.");
        return 1;
    }
    
    // inode now contains inode number of the file with descriptor fd. I used unsigned long long to avoid compile-time warnings.
    unsigned long long inode = file_stat.st_ino;
    printf("%llu\n", inode);
    
    return 0;
}
