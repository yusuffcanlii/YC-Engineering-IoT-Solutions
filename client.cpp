#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <thread>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

// --- YC ENGINEERING - FIELD UNIT (YC-X1) ---
// Unit ID: YC-X1

int main() {
    // Winsock Start
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Socket Create
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Target Address (Localhost)
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    cout << "--- YC ENGINEERING FIELD UNIT (YC-X1) ---\n";
    cout << "[INIT] Connecting to Master Control Grid...\n";

    // Connect
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "!!! CONNECTION ERROR: Server unreachable.\n";
        return 1;
    }

    cout << "[LINK] Secure Connection Established.\n\n";

    // Data Loop
    int temp = 22;
    while (true) {
        // Simulation
        temp += (rand() % 5) - 2; 
        
        // Protocol Packing
        string msg = "UNIT:YC-X1 | SENSOR:" + to_string(temp) + "C | STATUS:OPERATIONAL";
        
        // Send
        send(clientSocket, msg.c_str(), msg.length(), 0);
        cout << ">> [TX] Data Sent: " << msg << endl;

        // Receive ACK
        char buffer[1024];
        memset(buffer, 0, 1024);
        recv(clientSocket, buffer, 1024, 0);
        cout << "<< [RX] Server Response: " << buffer << "\n\n";

        // Wait 2 Seconds
        this_thread::sleep_for(chrono::seconds(2));
    }

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}