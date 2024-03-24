//
// Created by Administrator on 2023/12/22.
//

#include "GenerateAlgorithm.h"
std::vector<uint16_t> linear_generate(uint16_t first_item, uint16_t last_item, size_t num) {
	std::vector<uint16_t> result;

	if (num <= 1) {
		// If num is 0 or 1, return a vector with only the first_item
		result.push_back(first_item);
		return result;
	}

	// Calculate the step size
	double step = static_cast<double>(last_item - first_item) / (num - 1);

	// Generate the items
	for (size_t i = 0; i < num; ++i) {
		uint16_t value = static_cast<uint16_t>(first_item + i * step + 0.5); // Adding 0.5 for rounding
		result.push_back(value);
	}

	return result;
}