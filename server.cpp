#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

// --- YC ENGINEERING - MASTER CONTROL GRID ---
// Lead Engineer: Yusuf Canli
// System: Industrial Data Server v3.0

int main() {
    // 1. WINSOCK START
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 2. SOCKET SETUP
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; 
    serverAddr.sin_port = htons(8080); // Port 8080

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 1);

    // 3. INTERFACE (YUSUF CANLI SIGNATURE)
    cout << "=================================================\n";
    cout << "   YC ENGINEERING - MASTER CONTROL GRID v3.0     \n";
    cout << "   Lead Engineer: Yusuf Canli                    \n";
    cout << "=================================================\n";
    cout << "[SYS_INIT] Network protocols started...\n";
    cout << "[LISTEN]   Listening on Port 8080...\n";
    cout << "[WAIT]     Waiting for Field Unit connection...\n";

    // Accept Connection
    SOCKET clientSocket;
    sockaddr_in clientAddr;
    int clientSize = sizeof(clientAddr);
    clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);

    cout << "\n>> [LINK ESTABLISHED] YC-X1 Unit Connected.\n";
    cout << "-------------------------------------------------\n";

    char buffer[1024]; 
    
    // 4. DATA LOOP (AUTOMATED)
    while (true) {
        memset(buffer, 0, 1024);
        
        // Receive Data
        int bytesReceived = recv(clientSocket, buffer, 1024, 0);
        if (bytesReceived <= 0) {
            cout << "[ALERT] Connection lost. Target offline.\n";
            break;
        }

        // Log Data to Console
        cout << "[TELEMETRY]: " << buffer << endl;

        // Auto-Response (No Manual Input)
        string ackMsg = "ACK_YC_ENG_200: DATA_SECURED"; 
        send(clientSocket, ackMsg.c_str(), ackMsg.length(), 0);
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}