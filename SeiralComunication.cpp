//
// Created by Administrator on 2023/12/22.
//

#include <iostream>
#include <fstream>
#include "SeiralComunication.h"

bool setupSerialPort(HANDLE& hSerial, const LPCWSTR portName, DWORD baudRate) {
	std::wcout<<portName<<std::endl;
	hSerial = CreateFile(reinterpret_cast<LPCSTR>(portName),
		GENERIC_READ | GENERIC_WRITE,
		0,
		nullptr,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		nullptr);

	if (hSerial == INVALID_HANDLE_VALUE) {
		std::cerr << "Error opening serial port" << std::endl;
		return false;
	}

	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hSerial, &dcbSerialParams)) {
		std::cerr << "Error getting current serial port state" << std::endl;
		return false;
	}

	dcbSerialParams.BaudRate = baudRate;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

	if (!SetCommState(hSerial, &dcbSerialParams)) {
		std::cerr << "Error setting serial port state" << std::endl;
		return false;
	}

	return true;
}

void writeSerialPort(HANDLE hSerial, const std::vector<uint16_t>& data) {
	for (const auto& value : data) {
		// Transmit low byte first
		auto lowByte = static_cast<uint8_t>(value & 0xFF);
		auto highByte = static_cast<uint8_t>(value >> 8);

		DWORD bytesWritten;
		if (!WriteFile(hSerial, &lowByte, 1, &bytesWritten, nullptr) ||
			!WriteFile(hSerial, &highByte, 1, &bytesWritten, nullptr)) {
			std::cerr << "Error writing to serial port" << std::endl;
			break;
		}
	}
}

void readSerialPortAndSaveToFile(HANDLE hSerial, const std::string& filePath, size_t bytesToRead) {
	std::vector<uint8_t> buffer(bytesToRead);
	DWORD bytesRead;

	if (!ReadFile(hSerial, buffer.data(), bytesToRead, &bytesRead, NULL)) {
		std::cerr << "Error reading from serial port" << std::endl;
		return;
	}

	std::ofstream outFile(filePath, std::ios::binary);
	if (!outFile) {
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}

	outFile.write(reinterpret_cast<const char*>(buffer.data()), bytesRead);
	outFile.close();
	for(auto byte:buffer)
	{
		printf("Value in hexadecimal: 0x%02X\n", byte);
	}
}