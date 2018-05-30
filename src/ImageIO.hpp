#pragma once

#include <string>
#include <memory>

namespace ImageIO {

std::unique_ptr<float[]> LoadEXR(
	const std::string &file_name,
	int &width, int &height
);

}
