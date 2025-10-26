#include <stdio.h>
#include <string.h>

void process_login(char* username_input) {
    // These variables are placed "adjacently" on the stack.
    // 'is_admin' is likely placed right after 'username_buffer'.
    char username_buffer[20];
    int is_admin = 0; // 0 = false, 1 = true

    // VULNERABILITY: strcpy is used again.
    // The 'username_buffer' is only 20 bytes.
    strcpy(username_buffer, username_input);

    // If 'username_input' is "MyUsername\0\0\0\0\0\0\0\0\0\0\0\0\0\1",
    // the copy will fill the 20-byte buffer and the extra bytes
    // will "overflow" and overwrite the 'is_admin' variable,
    // setting it to 1 (true).

    if (is_admin) {
        printf("Welcome, ADMINISTRATOR!\n");
        // Attacker has successfully gained admin privileges
    } else {
        printf("Welcome, %s.\n", username_buffer);
    }
}

int main() {
    // 24-byte string: 20 A's, then 4 bytes to represent '1' (as an int)
    char* attack_string = "AAAAAAAAAAAAAAAAAAAA\x01\x00\x00\x00";
    process_login(attack_string);
    return 0;
}