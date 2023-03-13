
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <dirent.h>
#include <errno.h>
#include "vars.h"


void check_file_uploads() {
    // Open the shared directory
    DIR* shared_dir = opendir(maindir);
    if (shared_dir == NULL) {
        syslog(LOG_ERR, "Failed to open shared directory: %s", strerror(errno));
        return;
    }

    // Open the reporting directory
    DIR* reporting_dir = opendir(report);
    if (reporting_dir == NULL) {
        syslog(LOG_ERR, "Failed to open reporting directory: %s", strerror(errno));
        closedir(shared_dir);
        return;
    }

    // Loop over files in the shared directory
    struct dirent* file;
    while ((file = readdir(shared_dir)) != NULL) {
        // Ignore hidden files
        if (file->d_name[0] == '.') {
            continue;
        }

        // Build the full path to the file in the shared directory
        char shared_path[PATH_MAX];
        snprintf(shared_path, sizeof(shared_path), "%s/%s", maindir, file->d_name);

        // Check if the file has already been processed
        if (access(shared_path, F_OK) == -1) {
            // Build the full path to the file in the reporting directory
            char reporting_path[PATH_MAX];
            snprintf(reporting_path, sizeof(reporting_path), "%s/%s", report, file->d_name);

            // Move the file to the reporting directory
            if (rename(shared_path, reporting_path) == -1) {
                syslog(LOG_ERR, "Failed to move file: %s", strerror(errno));
            } else {
                syslog(LOG_INFO, "Moved file %s to reporting directory", file->d_name);
            }
        }
    }

    // Close directories
    closedir(shared_dir);
    closedir(reporting_dir);
}




      