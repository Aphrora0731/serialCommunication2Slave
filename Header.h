//
// Created by Administrator on 2023/12/22.
//

#ifndef _HEADER_H_
#define _HEADER_H_

#include <cstdint>
#include <vector>
const size_t HEADER_LEN = 7;
const size_t X_POINT_NUM = 0;
const size_t X_BLOCK_NUM = 1;
const size_t Y_POINT_NUM = 2;
const size_t CYCLES_PER_POINT = 3;
const size_t DAC_DELAY_CYCLES = 4;
const size_t ACQ_DELAY_CYCLES = 5;
const size_t CCD_DELAY_CYCLES = 6;

class Header
{
 public:
	Header(uint16_t xdata_points_number,
		uint16_t xdata_block_number,
		uint16_t ydata_points_number,
		uint16_t cycles_per_points,
		uint16_t da_delay_cycles,
		uint16_t acq_delay_cycles,
		uint16_t ccd_delay_cycles);
	std::vector<uint16_t> content;
};

#endif //_HEADER_H_
