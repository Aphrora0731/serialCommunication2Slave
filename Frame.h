//
// Created by Administrator on 2023/12/22.
//

#ifndef _FRAME_H_
#define _FRAME_H_

#include <vector>
#include <cstdint>
#include <string>
#include "Header.h"
class Frame
{
	Header header;
 public:
	explicit Frame(Header header);
	void generate_x(std::vector<uint16_t> xdata);
	void generate_y(std::vector<uint16_t> ydata);
	void save_to(const std::string& file_path);
	std::vector<uint16_t> content;
};

#endif //_FRAME_H_
