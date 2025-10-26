#include <stdio.h>
#include <string.h>

void vulnerable_function(char* input_string) {
    char buffer[16];  // Stack buffer for 16 bytes

    // VULNERABILITY: strcpy has no bounds checking
    // Input longer than 16 bytes will overflow the buffer
    strcpy(buffer, input_string);

    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        vulnerable_function(argv[1]);  // Pass user input directly
    }
    return 0;
}
