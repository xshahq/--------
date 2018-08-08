#include <stdio.h>
#include <string.h>
int code[8][1<<8];
int readChar() {
    while(true) {
        int ch = getchar();
        if(ch != '\n' && ch != '\r') {
            return ch;
        }
    }
}

int readInt(int c) {
    int v = 0;
    while(c--) {
        v = v * 2 + readChar() - '0';
    }
    return v;
}

int readCodes() {
    memset(code, 0, sizeof(code));
    code[1][0] = readChar();
    for(int len = 2; len <= 7; len++) {
        for(int i = 0; i < (1 << len) - 1; i++) {
            int ch = getchar();
            if(ch == EOF) {
                return 0;
            }
            if(ch == '\n' || ch == '\r') {
                return 1;
            }
            code[len][i] = ch;
        }
    }
    return 1;
}

int main() {
    while(readCodes()) {
        while(true) {
            int len = readInt(3);
            if(!len) {
                break;
            }
            while(true) {
                int v = readInt(len);
                if(v == (1 << len) - 1) {
                    break;
                }
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }

    return 0;
}