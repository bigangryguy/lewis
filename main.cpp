#include <iostream>
#include <fstream>
#include "vec3.h"

int main() {
	std::ofstream file;
	file.open("test.ppm");
	int nx = 200;
	int ny = 100;
	file << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			lewis::vec3 col(double(i) / double(nx), double(j) / double(ny), 0.2);
			int ir = int(255.99 * col.r());
			int ig = int(255.99 * col.g());
			int ib = int(255.99 * col.b());
			file << ir << " " << ig << " " << ib << "\n";
		}
	}
	file.close();
}