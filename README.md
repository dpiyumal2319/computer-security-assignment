# Computer Security Assignment: Program Vulnerabilities

This assignment demonstrates common program vulnerabilities and their fixes through small code segments. Each vulnerability is illustrated with a vulnerable code example and a corresponding fixed version.

## 1. Stack Smashing (Buffer Overflow)

### Vulnerable Code: `1_stack_smash.c`
This code uses `strcpy()` to copy user input into a fixed-size buffer without checking the input length. An attacker can provide a long string that overflows the buffer, potentially overwriting adjacent stack data and causing crashes or arbitrary code execution.

### Fixed Code: `1_stack_smash_fix.c`
The fix uses `snprintf()` with the buffer size to prevent overflow. This ensures only the safe amount of data is copied, protecting the stack integrity.

## 2. No Range Checking (Array Out of Bounds)

### Vulnerable Code: `2_no_range_check.c`
This code directly uses user-provided input as an array index without validation. An attacker can supply invalid indices (negative or beyond array bounds) to read or write outside the array, potentially leaking sensitive data or causing crashes.

### Fixed Code: `2_no_range_check_fix.c`
The fix implements bounds checking by validating the index is within the valid range (0 to MAX_USERS-1) before accessing the array. Invalid inputs are handled gracefully with error messages.

## 3. Adjacent Variable Overflow

### Vulnerable Code: `3_adjacent_overflow.c`
This code places a buffer and an `is_admin` flag adjacently on the stack. Using `strcpy()` allows an attacker to overflow the buffer and overwrite the flag, granting unauthorized privileges.

### Fixed Code: `3_adjacent_overflow_fix.c`
The fix switches to C++ and uses `std::string`, which manages memory safely and prevents overflow into adjacent variables. The string automatically resizes to fit input without corrupting nearby data.

## 4. Pointer Exploitation

### Vulnerable Code: `4_pointer_exploit.c`
This code stores a function pointer on the stack next to a buffer. A buffer overflow via `strcpy()` can overwrite the pointer, redirecting execution to malicious code instead of the intended function.

### Fixed Code: `4_pointer_exploit_fix.c`
The fix uses `snprintf()` to prevent buffer overflow, ensuring the function pointer remains unmodified and execution stays safe.

## 5. SQL Injection

### Vulnerable Code: `5_sql_injection.js`
This Node.js/Express code concatenates user input directly into SQL queries. An attacker can inject malicious SQL (e.g., `' OR 1=1 --`) to bypass authentication or manipulate the database.

### Fixed Code: `5_sql_injection_fix.js`
The fix uses parameterized queries with placeholders (`?`) and passes user input separately. The database driver safely binds the input, treating it as data rather than executable SQL, preventing injection attacks.

## Security Mitigations Implemented

- **Bounds Checking**: Applied in the array access fix to validate indices.
- **Safe String Handling**: Used in buffer overflow fixes to prevent memory corruption.
- **Parameterized Queries**: Implemented for SQL injection prevention to separate code from data.

These examples demonstrate how small coding oversights can lead to serious vulnerabilities and how proper defensive programming can mitigate them.