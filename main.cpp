#include <iostream>
#include "Frame.h"
#include "GenerateAlgorithm.h"
#include "SeiralComunication.h"
#include <windows.h>
const uint16_t xpn = 1200;//10;//x points number
const uint16_t xbn = 200;//3;//x blocked number
const uint16_t ypn = 1000;//10;
const uint16_t cpp = 1000;//cycles per point
const uint16_t dad = 0;//0;//da delay cycles
const uint16_t acd = 1000;//3500;
const uint16_t cdd = 500;//0;
const uint16_t x_init = 4096;
const uint16_t x_end = 12288;
const uint16_t y_init = 4096;
const uint16_t y_end = 12288;
const std::string frame_bin_file_path = R"(D:\XilinxProjects\OCT_DDS_driver_verification\bytes.bin)";
//R"(D:\XilinxProjects\OCT_driver_verification\OCT_driver_verification.srcs\byteFlowSim\new\bytes.mem)";
int main()
{
	Frame frame({ xpn, xbn, ypn, cpp, dad, acd, cdd });
	std::vector<uint16_t> xdata(xbn, x_init);
	std::vector<uint16_t> linear_data = linear_generate(x_init, x_end, xpn - xbn);
	for (unsigned short i : linear_data)
	{
		xdata.push_back(i);
	}
	std::vector<uint16_t> ydata = linear_generate(y_init, y_end, ypn);
	frame.generate_x(xdata);
	frame.generate_y(ydata);

	frame.save_to(frame_bin_file_path);
	HANDLE hSerial;


	if (!setupSerialPort(hSerial, reinterpret_cast<LPCWSTR const>("\\\\.\\COM11"), CBR_115200))
	{
		system("pause");
		return 1;
	}

	writeSerialPort(hSerial, frame.content);
	//readSerialPortAndSaveToFile(hSerial, "../recv.bin", 1000);
	CloseHandle(hSerial); // Close the serial port
	return 0;

}
