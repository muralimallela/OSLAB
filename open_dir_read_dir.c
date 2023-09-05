#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h> // Include string.h for strerror

extern int errno;

int main() {
    int fd;
    fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("Error in opening file");
        printf("Error code: %d\n", errno);
        printf("Error description: %s\n", strerror(errno));
    } else {
        printf("File opened successfully with file descriptor %d\n", fd);
    }
    return 0;
}
