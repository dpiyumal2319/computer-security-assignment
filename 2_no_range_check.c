#include <stdio.h>

int user_scores[10] = {100, 90, 85, 95, 70, 60, 75, 80, 92, 88};

void print_score(int user_id) {
    
    // VULNERABILITY: No bounds checking on array index
    // Negative or out-of-range values will access arbitrary memory
    printf("Score for user %d: %d\n", user_id, user_scores[user_id]);
}

int main() {
    int user_id_from_attacker = 10;  // Out of bounds (valid: 0-9)
    print_score(user_id_from_attacker);
    return 0;
}
