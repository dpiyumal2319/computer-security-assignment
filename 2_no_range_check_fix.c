#include <stdio.h>

int user_scores[10] = {100, 90, 85, 95, 70, 60, 75, 80, 92, 88};

// This constant helps us know the array size
#define MAX_USERS 10

void safe_print_score(int user_id) {

    // FIX: Perform bounds checking.
    // We check if the 'user_id' is greater than or equal to 0
    // AND less than the total number of items (MAX_USERS).
    if (user_id >= 0 && user_id < MAX_USERS) {
        // Only access the array if the index is valid
        printf("Score for user %d: %d\n", user_id, user_scores[user_id]);
    } else {
        // Handle the error case gracefully
        printf("Error: Invalid user ID %d.\n", user_id);
    }
}

int main() {
    int user_id_from_attacker = 10;
    safe_print_score(user_id_from_attacker); // Will now print an error
    
    int valid_id = 3;
    safe_print_score(valid_id); // Works correctly
    return 0;
}