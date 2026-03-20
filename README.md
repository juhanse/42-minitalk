*This project has been created as part of the 42 curriculum by juhanse.*

# 🤖 Description

This project is a **C++ Web Server** implementation that simulates core functionalities of servers like Nginx.  
It handles HTTP requests, serves static content, manages multiple server blocks, and supports basic CGI scripts.  
Minitalk is a small client-server communication program based on **UNIX signals**. The goal is to transmit a string of characters from a client process to a server process using only `SIGUSR1` and `SIGUSR2`.

> Goal: Reliable data transmission using bit-shifting and signal handling.
### Features:
- Supports Unicode (UTF-8)
- Multiple simultaneous clients
- Includes an **acknowledgment (ACK)** system for synchronized communication



# 🧰 Instructions
### Compilation
Use the provided `Makefile` to compile the project:
```bash
make        # Compiles mandatory files
make bonus  # Compiles bonus files (ACK & Unicode support)
```

### Execution
1. **Start the server first:**
   ```bash
   ./server
   ```
   The server will display its **PID** (Process ID).

2. **Run the client in a separate terminal:**
   ```bash
   ./client <SERVER_PID> "Your message here"
   ```


# 📚 Resources
### References
* Unix Signals: `man signal`, `man sigaction`, `man kill`.
* Bitwise Operations: [C Bitwise Operators Guide](https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm).
* UTF-8 Encoding: Understanding how multi-byte characters are structured in memory.

### AI was used to:
* Code Logic: Clarifying the use of `siginfo_t` to retrieve the client's PID for acknowledgments.
* Debugging: Troubleshooting "Race Conditions" and signal loss on macOS/Linux environments.
