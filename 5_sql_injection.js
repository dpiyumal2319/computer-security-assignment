// Assume 'app' is an Express.js app and 'db' is a database connection.

// A vulnerable API endpoint for logging in a user
app.post('/login', (req, res) => {
    
    // 1. Get username from the request body.
    // Example: req.body.username = "alice";
    const username_input = req.body.username;
    const password_input = req.body.password; // Also vulnerable!

    // 2. VULNERABILITY: Build the SQL query by concatenating the
    //    raw, untrusted user input directly into the string.
    const sql = "SELECT * FROM users WHERE username = '" + username_input + 
                "' AND password = '" + password_input + "'";

    // 3. What if the attacker's input for username is: ' OR 1=1 --
    //    The final query becomes:
    //    SELECT * FROM users WHERE username = '' OR 1=1 --' AND password = '...'"
    //
    //    The 'OR 1=1' is always true, and the '--' comments out the
    //    rest of the query, so the password check is skipped.
    //    The query returns *all users* and the attacker is logged in
    //    as the *first user* in the database (often an admin).

    db.query(sql, (err, results) => {
        if (results.length > 0) {
            // Attacker is successfully logged in!
            res.send("Login successful!");
        } else {
            res.send("Login failed.");
        }
    });
});