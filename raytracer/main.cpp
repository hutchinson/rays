#include <iostream>

#include "vec3.hpp"

int main(int argc, const char** argv)
{
    constexpr int nx = 200;
    constexpr int ny = 100;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for(int j = ny - 1; j >= 0; --j)
    {
        // Print 1 row at a time...
        for(int i = 0; i < nx; ++i)
        {
            // Far left will mean no red, as we approach the right we'll see more red in the mix.
            // Top of the image we'll see more green which will slowly fade out.
            // Constant
            vec3 colour(float(i) / float(nx), float(j) / float(ny), 0.2f);

            int ir = int(255.99 * colour.r());
            int ig = int(255.99 * colour.g());
            int ib = int(255.99 * colour.b());

            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }

    return 0;
}
