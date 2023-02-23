#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char * fifoFile = "/tmp/fifoFile";

    /* create the FIFO (named pipe) */
    mkfifo(fifoFile, 0666);

    fd = open(fifoFile, O_WRONLY);
    write(fd, "The truth is out there!!", sizeof("The truth is out there!!"));
    close(fd);

    unlink(fifoFile);

    return 0;
}
