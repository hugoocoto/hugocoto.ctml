#include <assert.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ctml.h"
char html[1024 * 1024];

int
main()
{
/*   */ #define FILENAME "mainpage.ctml"
/*   */ #define OUTNAME "index.html"
/*   */ #include "build.c"

/*   */ #define FILENAME "library.ctml"
/*   */ #define OUTNAME "library.html"
/*   */ #include "build.c"

/*   */ #define FILENAME "vicel.ctml"
/*   */ #define OUTNAME "vicel.html"
/*   */ #include "build.c"
        return 0;
}
