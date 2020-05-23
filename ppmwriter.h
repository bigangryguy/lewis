#pragma once

#include <string>
#include "vec3.h"

namespace lewis
{
	class PPMWriter
	{
	public:
        PPMWriter() = delete;

		static void Write(const std::string& filename, const Vec3Matrix& vector_matrix);
	};
}