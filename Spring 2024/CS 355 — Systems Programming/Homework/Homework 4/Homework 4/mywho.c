//
//  mywho.c
//  Homework 4
//
//  Created by Rumman Shahzad on 3/4/24.
//

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SHOWHOST // Include remote machine

int main(int argc, const char * argv[]) {

    // Buffer and file descriptor for reading data
    struct utmp record;
    int fd;
    
    // Open utmp file, exit if not opened
    if ((fd = open(UTMP_FILE, O_RDONLY)) == -1) {
        perror(UTMP_FILE); // UTMP_File is in utmp.h
        exit(1);
    }

    // Copy structs in utmp to buffer and print one by one
    while (read(fd, &record, sizeof(record))) {
        
        if (record.ut_type == USER_PROCESS) {

            // Print login user name and line
            printf("%s ", record.ut_name);
            printf("%s        ", record.ut_line);

            // Convert timestamp to a formatted date/time and print it out
            time_t timestamp = record.ut_time;
            struct tm *tm_info = localtime(&timestamp);
            printf("%04d-%02d-%02d %02d:%02d", tm_info->tm_year + 1900, tm_info->tm_mon + 1, tm_info->tm_mday, tm_info->tm_hour, tm_info->tm_min);

            // Print host address from buffer
            #ifdef SHOWHOST
                printf(" (%s)", record.ut_host);
            #endif
                printf("\n");
        }
    }

    // Printing successful
    close(fd);
    return 0;
}
