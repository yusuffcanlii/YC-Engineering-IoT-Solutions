# 🏭 YC ENGINEERING - INDUSTRIAL IoT CONTROL GRID

![Project Status](https://img.shields.io/badge/Status-Operational-success)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Protocol](https://img.shields.io/badge/Protocol-TCP%2FIP-orange)

## 📋 Project Overview
**YC Engineering Industrial IoT System** is a robust simulation of a real-time industrial network architecture. Developed using **C++** and **Windows Sockets (Winsock)**, this project demonstrates a reliable **Client-Server communication model** typically used in defense and automation sectors.

The system consists of a **Master Control Grid (Server)** and autonomous **Field Units (Clients)** communicating over TCP/IP with an automated handshake protocol.

---

## 🚀 Key Features
* **Real-Time Telemetry:** Instant transmission of sensor data (Temperature, Status, Unit ID) from field nodes.
* **TCP/IP Socket Architecture:** Uses standard network protocols for reliable data delivery.
* **Automated Handshake (ACK):** The server automatically validates and acknowledges every data packet received (`ACK_YC_ENG_200`).
* **Industrial Simulation:** Simulates environmental fluctuations and sensor noise.

---

## 🛠️ Architecture

### 1. Master Control Grid (Server)
* **Role:** Central Command Center.
* **Function:** Listens on Port `8080`, accepts incoming connections, logs telemetry data, and sends acknowledgment signals.
* **Tech:** Multithreaded socket handling (simulated).

### 2. Field Unit YC-X1 (Client)
* **Role:** Remote Sensor Node.
* **Function:** Generates synthetic sensor data, packages it into the **YC-Protocol**, and transmits it to the Master Grid.
* **Behavior:** Waits for server confirmation (ACK) before the next cycle.

---

## 💻 Usage & Compilation

This project is designed for **Windows** environments using MinGW/G++ compiler.

### Prerequisites
* G++ Compiler (MinGW)
* Windows OS (Required for `winsock2.h`)

### Step 1: Start the Master Server
Open a terminal and run:
```bash
g++ server.cpp -o server -lws2_32
.\server