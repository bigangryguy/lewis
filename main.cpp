#include "vec3.h"
#include "ray.h"
#include "ppmwriter.h"

lewis::Vec3 color(const lewis::Ray& r)
{
    auto unit_direction = lewis::unit_vector(r.Direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * lewis::Vec3{1.0, 1.0, 1.0} + t * lewis::Vec3{ 0.5, 0.7, 1.0 };
}

int main()
{
    constexpr int nx = 200;
    constexpr int ny = 100;

    lewis::Vec3Matrix sample{ny};

    lewis::Vec3 lower_left_corner{ -2.0, -1.0, -1.0 };
    lewis::Vec3 horizontal{ 4.0, 0.0, 0.0 };
    lewis::Vec3 vertical{ 0.0, 2.0, 0.0 };
    lewis::Vec3 origin{ 0.0, 0.0, 0.0 };
    for (int j = 0; j < ny; j++)
    {
        const int y = ny - j - 1;
        sample[y] = std::vector<lewis::Vec3>{nx};
        for (int i = 0; i < nx; i++)
        {
            double u = double(i) / double(nx);
            double v = double(j) / double(ny);
            lewis::Ray r{ origin, lower_left_corner + u * horizontal + v * vertical };
            lewis::Vec3 col = color(r);
            sample[y][i] = col;
        }
    }

    lewis::PPMWriter::Write("test.ppm", sample);
}