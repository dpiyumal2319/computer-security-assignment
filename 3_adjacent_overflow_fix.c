#include <iostream>
#include <string>

// We are now using C++ for a safer, modern solution
void safe_process_login(std::string username_input) {
    
    // FIX: std::string manages its own memory safely.
    // It will automatically resize to fit the input.
    // It is impossible for it to overflow into 'is_admin'.
    std::string username = username_input;
    int is_admin = 0;

    // (Note: In a real app, 'is_admin' would be set by
    // checking a database, not by being adjacent on the stack)
    
    if (is_admin) {
        std::cout << "Welcome, ADMINISTRATOR!" << std::endl;
    } else {
        std::cout << "Welcome, " << username << std::endl;
    }
}

int main() {
    // This long string is now handled safely.
    std::string attack_string = "AAAAAAAAAAAAAAAAAAAA\x01\x00\x00\x00";
    safe_process_login(attack_string); // Will just print the user's name
    return 0;
}