#include <unistd.h>

int main(int argc, char *argv[]) {
    char *msg = "Hello World";
    char buf;
    int i = 0;
    int j;
    char indent = '\n';
    // write()はFDにバイト列を書き込むための関数。第二引数には書き込むデータの先頭アドレスを渡す必要がある。
    for (i=1; i < argc; i++) {
        j = 0;
        while (1) {
            buf = argv[i][j];
            if (buf == '\0') {
                //write(1, &indent, 1);
                write(1, " ", 1);
                break;
            } else {
                write(1, &buf, 1);
            }
            j++;
        }
    }
    write(1, "\n", 1);

    return 0;
}
