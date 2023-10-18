#pragma once

#include <string>

namespace UtilsOne{
	std::string generateRandomID(int length);
	void generateRandomData(int size, std::string filename = "p1.txt");
};
