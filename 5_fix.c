// Demonstrates code-level fixes for buffer overflow vulnerabilities

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 

// --- Fix 1: Bounds checking with snprintf ---
void safe_function(char* input_string) {
    char buffer[16];

    // FIX: snprintf limits bytes written to buffer size
    snprintf(buffer, sizeof(buffer), "%s", input_string);

    printf("1. Canary/Bounds Fix: Buffer content is: %s\n", buffer);
}

// --- Fix 2: Validate array indices ---
int user_scores[10] = {100, 90, 85, 95, 70, 60, 75, 80, 92, 88};
#define MAX_USERS 10

void safe_print_score(int user_id) {
    // FIX: Check if index is within valid range
    if (user_id >= 0 && user_id < MAX_USERS) {
        printf("2. Bounds Check Fix: Score for user %d: %d\n", user_id, user_scores[user_id]);
    } else {
        printf("2. Bounds Check Fix: Error: Invalid user ID %d.\n", user_id);
    }
}

// --- Fix 3: Use safe string types ---
void safe_process_login(std::string username_input) {
    
    // FIX: std::string auto-manages memory and prevents overflow
    std::string username = username_input;
    int is_admin = 0;

    if (is_admin) {
        std::cout << "3. Tagging/Safe-Type Fix: Welcome, ADMINISTRATOR!" << std::endl;
    } else {
        std::cout << "3. Tagging/Safe-Type Fix: Welcome, " << username << std::endl;
    }
}

int main() {
    
    // Test 1: Long string that would overflow
    char* long_attack_string = "ThisIsAVeryLongStringThatWouldOverflowTheBuffer";
    printf("--- Testing Fix 1 (Canary/Bounds) ---\n");
    safe_function(long_attack_string);

    // Test 2: Out-of-bounds index
    int invalid_id = 10;
    printf("\n--- Testing Fix 2 (Bounds Checking) ---\n");
    safe_print_score(invalid_id);
    safe_print_score(3);

    // Test 3: String that would overflow adjacent variable
    std::string adjacent_attack_string = "AAAAAAAAAAAAAAAAAAAA\x01\x00\x00\x00";
    printf("\n--- Testing Fix 3 (Tagging/Safe Types) ---\n");
    safe_process_login(adjacent_attack_string);

    return 0;
}
