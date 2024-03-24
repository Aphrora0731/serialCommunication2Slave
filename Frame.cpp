//
// Created by Administrator on 2023/12/22.
//

#include "Frame.h"

#include <utility>
#include <iostream>
#include <fstream>
Frame::Frame(Header header)
	: header(header), content(header.content)
{
	//compute frame size(count by word)
	size_t frame_size = HEADER_LEN + header.content[X_POINT_NUM] + header.content[Y_POINT_NUM];
	content.reserve(frame_size);
}
void Frame::generate_x(std::vector<uint16_t> xdata)
{
	if (xdata.size() != header.content[X_POINT_NUM])
	{
		std::cerr << "generate_x(std::vector<uint16_t>,Frame.cpp FUCK YOU\n";
		return;
	}
	for (unsigned short i : xdata)
	{
		content.push_back(i);
	}
}
void Frame::generate_y(std::vector<uint16_t> ydata)
{

	if (ydata.size() != header.content[Y_POINT_NUM])
	{
		std::cerr << "generate_y(std::vector<uint16_t>,Frame.cpp FUCK YOU\n";
		return;
	}

	for (unsigned short i : ydata)
	{
		content.push_back(i);
	}
}
void Frame::save_to(const std::string& file_path)
{
	std::ofstream file(file_path,std::ios::binary);
	if(!file){
		std::cerr<<"Cant create file\n";
		return;
	}
	for (uint16_t value : content) {
		file.write(reinterpret_cast<const char*>(&value), sizeof(value));
	}
	file.close();
}
