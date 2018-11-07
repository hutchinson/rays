#include <iostream>

#include "vec3.hpp"
#include "ray.hpp"

vec3 shader(const ray& r)
{
    vec3 unit_direction = unit_vector(r.direction());

    float t = 0.5f * (unit_direction.y() * 1.0f);
    return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

int main(int argc, const char** argv)
{
    constexpr int nx = 200;
    constexpr int ny = 100;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
    vec3 horizontal(4.0f, 0.0f, 0.0f);
    vec3 vertical(0.0f, 2.0f, 0.0f);
    vec3 origin(0.0f, 0.0f, 0.0f);

    for(int j = ny - 1; j >= 0; --j)
    {
        // Print 1 row at a time...
        for(int i = 0; i < nx; ++i)
        {
            const float u = float(i) / float(nx);
            const float v = float(j) / float(ny);

            ray r(origin, lower_left_corner + (u * horizontal) + (v * vertical));
            vec3 colour = shader(r);

            int ir = int(255.99f * colour.r());
            int ig = int(255.99f * colour.g());
            int ib = int(255.99f * colour.b());

            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }

    return 0;
}
