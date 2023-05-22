#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

void print(char* argv) {
    int i = 0;
    char buf;
    while (1) {
        buf = argv[i];
        if (buf == '\0') {
            write(1, "\n", 1);
            break;
        } else {
            write(1, &buf, 1);
        }
        i++;
    }
}

// get file and show the content

int main(int argc, char *argv[]) {
    int fd;
    size_t buff_size = 256;
    char buff[buff_size];
    int res;

    if (argc != 2) {
        print("this command take exactly 1 argument..");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        print("no such a file..");
        return -1;
    }
    while (read(fd, buff, buff_size) != 0) {
        print(buff);
    }

    
    return 0;
}
