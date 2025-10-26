#include <stdio.h>
#include <string.h>

void safe_function(char* input_string) {
    char buffer[16];

    // FIX: snprintf() is a "safe" function.
    // It takes the buffer's size (sizeof(buffer)) as an argument
    // and guarantees it will not write more than that many bytes.
    snprintf(buffer, sizeof(buffer), "%s", input_string);

    // Now, even if 'input_string' is 1000 bytes long, only the
    // first 15 bytes (+ null terminator) will be copied.
    // The stack is not smashed, and the canary (if enabled) remains intact.

    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        safe_function(argv[1]);
    }
    return 0;
}
