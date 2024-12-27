#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

// Function to write string to a file
int write_to_file(const char *file, const char *text) {
    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error opening file %s: %s", file, strerror(errno));
        return -1;
    }

    if (fputs(text, fp) == EOF) {
        syslog(LOG_ERR, "Error writing to file %s: %s", file, strerror(errno));
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *text = argv[1];
    const char *file = argv[2];

    // Open syslog with the LOG_USER facility
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Write the string to the file and log the success
    if (write_to_file(file, text) == 0) {
        syslog(LOG_DEBUG, "Writing \"%s\" to %s", text, file);
    } else {
        syslog(LOG_ERR, "Failed to write to file %s", file);
        closelog();
        return EXIT_FAILURE;
    }

    // Close syslog
    closelog();
    return EXIT_SUCCESS;
}

