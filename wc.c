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
    // search how many "\n" in the file
    if (argc != 2) {
        print("this commnd take exactly 1 argument..");
        return -1;
    }
    
    int i;
    int cnt = 0;
    int buff_size = 256;
    char* buff[buff_size];
    int fd;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        print("no such a file..");
        return -1;
    }
    while (read(fd, buff, buff_size) != 0) {
        for (i=0; i<buff_size; i++) {
            //printf("%c\n", buff[i]);
            if (buff[i] == '\n') {
                cnt++;
            }
        }
    }

    /*
    char int_buffer[20];
    snprintf(int_buffer, sizeof(int_buffer), "%d", cnt);
    write(1, int_buffer, sizeof(int_buffer));
    */
    printf("wc %d", cnt);
    return 0;
}



      
