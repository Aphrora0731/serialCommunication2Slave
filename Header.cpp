//
// Created by Administrator on 2023/12/22.
//

#include "Header.h"
Header::Header(uint16_t xdata_points_number, uint16_t xdata_block_number, uint16_t ydata_points_number, uint16_t cycles_per_points, uint16_t da_delay_cycles, uint16_t acq_delay_cycles, uint16_t ccd_delay_cycles)
	: content(HEADER_LEN)
{
	content[X_POINT_NUM] = xdata_points_number;
	content[X_BLOCK_NUM] = xdata_block_number;
	content[Y_POINT_NUM] = ydata_points_number;
	content[CYCLES_PER_POINT] = cycles_per_points;
	content[DAC_DELAY_CYCLES] = da_delay_cycles;
	content[ACQ_DELAY_CYCLES] = acq_delay_cycles;
	content[CCD_DELAY_CYCLES] = ccd_delay_cycles;
}
