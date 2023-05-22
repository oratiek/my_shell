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

int main(int argc, char* argv[]) {
    // get two arguments
    if (argc != 3) {
        print("this command requires exactly 3 arguments..");
        return -1;
    }

    int buff_size = 256;
    char buff[buff_size];

    char* src = argv[1];
    char* dst = argv[2];
    int src_fd, dst_fd;
    src_fd = open(src, O_RDONLY);
    dst_fd = open(dst, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    // open check
    if (src_fd < 0) {
        print("no such a file..");
        return -1;
    }


    // read src step by step and write into dst
    while ( read(src_fd, buff, buff_size) != 0 ) {
        write(dst_fd, buff, buff_size);
    }

    close(src_fd);
    close(dst_fd);
    
    return 0;
}
