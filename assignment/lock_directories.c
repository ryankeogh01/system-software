
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <syslog.h>

void lock_directories() {
    printf("lock directory functionality should go here. fork/chmod will be used here to change permissions");

    char mode[4] = "0555";
    int i = strtol(mode, 0, 8);

    if(chmod(maindir, i ) == 0){
        openlog("Daemon upload lock", LOG_PID | LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "Directory now locked");
        closelog();

    } 
    else {
        openlog("lock err", LOG_PID | LOG_CONS, LOG_USER);
        syslog(LOG_INFO, "lock err");
        closelog();
    }

}