#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

class ray
{
public:
    ray() = default;
    ray(const vec3& a, const vec3& b) :
        m_origin(a),
        m_direction(b)
    {

    }

    vec3 origin() const { return m_origin; }
    vec3 direction() const { return m_direction; }
    vec3 point_at_parameter(float t) const { return m_origin + t * m_direction; }

    vec3 m_origin;
    vec3 m_direction;
};

#endif // RAY_HPP
