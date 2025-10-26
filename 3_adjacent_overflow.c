#include <stdio.h>
#include <string.h>

void process_login(char* username_input) {
    char username_buffer[20];  // Adjacent to is_admin on stack
    int is_admin = 0;

    // VULNERABILITY: Buffer overflow can corrupt adjacent variables
    strcpy(username_buffer, username_input);

    if (is_admin) {
        printf("Welcome, ADMINISTRATOR!\n");  // Attacker gains admin access
    } else {
        printf("Welcome, %s.\n", username_buffer);
    }
}

int main() {
    // 20 A's + 4 bytes to overwrite is_admin to 1
    char* attack_string = "AAAAAAAAAAAAAAAAAAAA\x01\x00\x00\x00";
    process_login(attack_string);
    return 0;
}