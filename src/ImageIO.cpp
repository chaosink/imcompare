#include "ImageIO.hpp"

#define TINYEXR_IMPLEMENTATION
#include <tinyexr/tinyexr.h>

namespace ImageIO {

std::unique_ptr<float[]> LoadEXR( // tinyexr
	const std::string &file_name,
	int &width, int &height
) {
	float *data; // width * height * RGBA
	const char *err;

	int ret = ::LoadEXR(&data, &width, &height, file_name.c_str(), &err);
	if(ret != 0) {
		fprintf(stderr, "Load EXR err: %s\n", err);
		return nullptr;
	}

	return std::unique_ptr<float[]>(data);
}

}
