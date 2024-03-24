//
// Created by Administrator on 2023/12/22.
//

#ifndef _SEIRALCOMUNICATION_H_
#define _SEIRALCOMUNICATION_H_
#include <windows.h>
#include <vector>
#include <cstdint>

bool setupSerialPort(HANDLE& hSerial, LPCWSTR portName, DWORD baudRate);

void writeSerialPort(HANDLE hSerial, const std::vector<uint16_t>& data);
void readSerialPortAndSaveToFile(HANDLE hSerial, const std::string& filePath, size_t bytesToRead);

#endif //_SEIRALCOMUNICATION_H_
