#include <stdio.h>
#include <string.h>

void vulnerable_function(char* input_string) {
    // 'buffer' is a 16-byte array allocated on the stack.
    char buffer[16];

    // VULNERABILITY: strcpy() copies all bytes from 'input_string'
    // into 'buffer' until it hits a null terminator.
    // It does NOT check if 'input_string' is longer than 16 bytes.
    strcpy(buffer, input_string);
    // If input_string is "AAAAAAAAAAAAAAAAAAAAAAAAAAAA",
    // it will overflow 'buffer' and overwrite adjacent stack data.

    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        // A malicious input string can be passed via command line.
        vulnerable_function(argv[1]);
    }
    return 0;
}
