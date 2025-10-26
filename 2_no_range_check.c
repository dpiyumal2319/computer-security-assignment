#include <stdio.h>

// A global array of scores
int user_scores[10] = {100, 90, 85, 95, 70, 60, 75, 80, 92, 88};

// Function to get a score by its ID (index)
void print_score(int user_id) {
    
    // VULNERABILITY: The 'user_id' is used directly as an array index.
    // If an attacker provides a 'user_id' of -1, 10, or 500,
    // the program will read memory *outside* the 'user_scores' array.
    // This can be used to leak sensitive data or cause a crash.
    printf("Score for user %d: %d\n", user_id, user_scores[user_id]);
}

int main() {
    // Attacker controls this input, e.g., from a web request
    int user_id_from_attacker = 10; // This is out of bounds (0-9)
    print_score(user_id_from_attacker);
    return 0;
}
