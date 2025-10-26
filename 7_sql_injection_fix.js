// Safe login endpoint using parameterized queries

app.post('/login', (req, res) => {

    const username_input = req.body.username;
    const password_input = req.body.password;

    // FIX: Parameterized query with placeholders
    const sql = "SELECT * FROM users WHERE username = ? AND password = ?";

    // Database treats inputs as data, not SQL commands
    db.query(sql, [username_input, password_input], (err, results) => {
        
        // Attack input ' OR 1=1 -- is treated as literal username
        // Query fails safely with no matching user
        
        if (results.length > 0) {
            res.send("Login successful!");
        } else {
            res.send("Login failed.");
        }
    });
});
