/* It's weird so I like it */
do {
        int len = snprintf(html, sizeof html,
/*                      */ #include FILENAME
                           ,
/*                      */ #include "head.ctml"
                           ,
/*                      */ #include "header.ctml"
                           ,
/*                      */ #include "index.ctml"
        );

        int fd = open(OUTNAME, O_WRONLY | O_CREAT, (mode_t) 0600);
        if (fd < 0) {
                perror("open");
                return 1;
        }

        ssize_t n = write(fd, html, len);
        printf(OUTNAME ": %zd bytes written\n", n);
        ftruncate(fd, n);
        printf("%s\n", html);
} while (0);
#undef FILENAME
#undef OUTNAME
