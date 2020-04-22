#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ppmwriter.h"

namespace lewis
{
	void PPMWriter::Write(const std::string& filename, const Vec3Matrix& vector_matrix) const
	{
		if (filename.length() == 0)
		{
			throw std::invalid_argument("filename argument cannot be empty");
		}

		std::ofstream file{};
		file.open(filename, std::ofstream::out);

		size_t nx = vector_matrix[0].size();
		size_t ny = vector_matrix.size();

		file << "P3\n" << nx << " " << ny << "\n255\n";

		for (int y = ny - 1; y >= 0; y--)
		{
			for (int x = 0; x < nx; x++)
			{
				file << int(255.99 * vector_matrix[y][x].r()) << " " 
					 << int(255.99 * vector_matrix[y][x].g()) << " " 
					 << int(255.99 * vector_matrix[y][x].b()) << "\n";
			}
		}

		file.flush();
		file.close();
	}
}