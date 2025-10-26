// Vulnerable login endpoint demonstrating SQL injection

app.post('/login', (req, res) => {
    
    const username_input = req.body.username;
    const password_input = req.body.password;

    // VULNERABILITY: String concatenation with untrusted input
    // Attacker input: ' OR 1=1 -- bypasses authentication
    const sql = "SELECT * FROM users WHERE username = '" + username_input + 
                "' AND password = '" + password_input + "'";

    db.query(sql, (err, results) => {
        if (results.length > 0) {
            res.send("Login successful!");  // Attacker logs in as first user
        } else {
            res.send("Login failed.");
        }
    });
});