// Assume 'app' is an Express.js app and 'db' is a database connection
// (e.g., from 'mysql2' or 'pg' library)

// A safe API endpoint using parameterized queries
app.post('/login', (req, res) => {

    // 1. Get username and password from the request body.
    const username_input = req.body.username;
    const password_input = req.body.password;

    // 2. FIX: Use a Prepared Statement.
    //    The SQL query template uses '?' as placeholders for data.
    const sql = "SELECT * FROM users WHERE username = ? AND password = ?";

    // 3. Pass the untrusted user input as a separate array.
    //    The database driver will safely "bind" this data to the
    //    placeholders, ensuring it is treated only as text,
    //    not as executable SQL commands.
    db.query(sql, [username_input, password_input], (err, results) => {
        
        // If an attacker inputs: ' OR 1=1 --
        // The database will *safely search* for a user whose
        // literal username is "' OR 1=1 --".
        // It will find no such user, and the attack fails.
        
        if (results.length > 0) {
            res.send("Login successful!");
        } else {
            res.send("Login failed.");
        }
    });
});
