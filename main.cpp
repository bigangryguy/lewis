#include "vec3.h"
#include "ray.h"
#include "ppmwriter.h"

double HitSphere(const lewis::Vec3& center, double radius, const lewis::Ray& r)
{
    const auto oc = r.Origin() - center;
    const auto a = dot(r.Direction(), r.Direction());
    const auto b = 2.0 * dot(oc, r.Direction());
    const auto c = dot(oc, oc) - radius * radius;
    const auto discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        return -1.0;
    }
    else
    {
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
}

lewis::Vec3 Color(const lewis::Ray& r)
{
    const auto t = HitSphere({ 0.0, 0.0, -1.0 }, 0.5, r);
    if (t > 0.0)
    {
        const auto N = lewis::unit_vector(r.PointAtParameter(t) - lewis::Vec3{0.0, 0.0, -1.0 });
        return 0.5 * lewis::Vec3{ N.x() + 1.0, N.y() + 1.0, N.z() + 1.0 };
    }
    const auto unit_direction = lewis::unit_vector(r.Direction());
    const auto t2 = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t2) * lewis::Vec3{1.0, 1.0, 1.0} + t2 * lewis::Vec3{ 0.5, 0.7, 1.0 };
}

int main()
{
    constexpr int nx = 800;
    constexpr int ny = 400;

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
            const double u = double(i) / double(nx);
            const double v = double(j) / double(ny);
            lewis::Ray r{ origin, lower_left_corner + u * horizontal + v * vertical };
            sample[y][i] = Color(r);
        }
    }

    lewis::PPMWriter::Write("test.ppm", sample);
}