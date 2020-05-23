#include "vec3.h"
#include "ppmwriter.h"

int main()
{
    constexpr int nx = 200;
    constexpr int ny = 100;

    lewis::Vec3Matrix sample{ny};

    for (int j = ny - 1; j >= 0; j--)
    {
        sample[j] = std::vector<lewis::Vec3>{nx};
        for (int i = 0; i < nx; i++)
        {
            lewis::Vec3 col(double(i) / double(nx), double(j) / double(ny), 0.2);
            sample[j][i] = col;
        }
    }

    lewis::PPMWriter::Write("test.ppm", sample);
}