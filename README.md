# Computer Security Assignment: Program Vulnerabilities

This assignment demonstrates common program vulnerabilities and their fixes through code segments.

## Tasks Overview

### Task 1: Stack Smashing - `1_stack_smash.c`
Uses `strcpy()` without bounds checking. Long input overflows the buffer and corrupts stack data.

### Task 2: No Range Checking - `2_no_range_check.c`
Uses user input directly as array index. Out-of-range values access arbitrary memory.

### Task 3: Adjacent Variable Overflow - `3_adjacent_overflow.c`
Buffer overflow overwrites adjacent `is_admin` flag on stack, granting unauthorized privileges.

### Task 4: Pointer Exploitation - `4_pointer_exploit.c`
Buffer overflow overwrites function pointer on stack, redirecting execution to malicious code.

### Task 5: Security Fixes - `5_fix.c`
Demonstrates three mitigation techniques:
- **Canary/Bounds Checking**: Uses `snprintf()` to limit buffer writes
- **Bounds Checking**: Validates array indices before access
- **Tagging/Safe Types**: Uses `std::string` to prevent overflow

### Task 6: SQL Injection Vulnerability - `6_sql_injection.js`
Concatenates user input into SQL query. Attacker injects `' OR 1=1 --` to bypass authentication.

### Task 7: SQL Injection Prevention - `7_sql_injection_fix.js`
Uses parameterized queries with placeholders. Database treats input as data, not SQL code.