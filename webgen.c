#include <assert.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#include "ctml.h"

char html[] =
#include "mainpage.ctml"
;

int
main()
{
        int fd = open("index.html", O_WRONLY | O_CREAT, (mode_t) 0600);
        if (fd < 0) {
                perror("open");
                return 1;
        }

        assert(sizeof html > sizeof(char *));
        ssize_t n = write(fd, html, sizeof html);
        printf("index.html: %zd bytes written\n", n);
        ftruncate(fd, n);
        printf("%s\n", html);

        return 0;
}
