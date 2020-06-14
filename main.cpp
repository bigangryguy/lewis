#include "vec3.h"
#include "ray.h"
#include "hitable.h"
#include "hitablelist.h"
#include "sphere.h"
#include "camera.h"
#include "ppmwriter.h"
#include <vector>
#include <memory>

lewis::Vec3 Color(const lewis::Ray& r, const lewis::HitableList& world)
{
    lewis::HitRecord rec;
    if (world.Hit(r, 0.0, MAXFLOAT, rec))
    {
        return 0.5 * lewis::Vec3{rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1 };
    }
    else
    {
        auto unitDirection = lewis::UnitVector(r.Direction());
        const double t = 0.5 * (unitDirection.y() + 1.0);
        return (1.0 - t) * lewis::Vec3{ 1.0, 1.0, 1.0 } + t * lewis::Vec3{ 0.5, 0.7, 1.0 };
    }
}

int main()
{
    constexpr int nx = 1600;
    constexpr int ny = 800;
    constexpr int ns = 16;

    lewis::Vec3Matrix sample{ny};

    const lewis::Vec3 lower_left_corner{ -2.0, -1.0, -1.0 };
    const lewis::Vec3 horizontal{ 4.0, 0.0, 0.0 };
    const lewis::Vec3 vertical{ 0.0, 2.0, 0.0 };
    const lewis::Vec3 origin{ 0.0, 0.0, 0.0 };

    std::vector<std::shared_ptr<lewis::Hitable>> hitList{
        std::make_shared<lewis::Sphere>(lewis::Vec3{ 0.0, 0.0, -1.0 }, 0.5),
        std::make_shared<lewis::Sphere>(lewis::Vec3{ 0.0, -100.5, -1 }, 100)
    };

    lewis::HitableList world{ hitList };
    lewis::Camera camera{};

    for (int j = 0; j < ny; j++)
    {
        const int y = ny - j - 1;
        sample[y] = std::vector<lewis::Vec3>{nx};
        for (int i = 0; i < nx; i++)
        {
            lewis::Vec3 color{ 0.0, 0.0, 0.0 };
            for (int s = 0; s < ns; s++)
            {
                const double u = double(i + drand48()) / double(nx);
                const double v = double(j + drand48()) / double(ny);
                const lewis::Ray r = camera.GetRay(u, v);
                color += Color(r, world);
            }
            color /= double(ns);

            sample[y][i] = color;
        }
    }

    lewis::PPMWriter::Write("test.ppm", sample);
}