#ifndef VEC3_HPP
#define VEC3_HPP

#include <iostream>
#include <cmath>

class vec3
{
public:
    vec3() {}
    vec3(float e0, float e1, float e2)
    {
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
    }

    float x() const { return e[0]; }
    float y() const { return e[1]; }
    float z() const { return e[2]; }

    float r() const { return e[0]; }
    float g() const { return e[1]; }
    float b() const { return e[2]; }

    // Basic operators
    const vec3& operator+() const { return *this; }
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    float operator[](int i) const { return e[i]; }
    float& operator[](int i) { return e[i]; }

    // Basic mathematical operations.
    vec3& operator+=(const vec3& rhs);
    vec3& operator-=(const vec3& rhs);
    vec3& operator*=(const vec3& rhs);
    vec3& operator/=(const vec3& rhs);

    vec3& operator*=(const float t);
    vec3& operator/=(const float t);

    float length() const {
        return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] + e[2]);
    }

    float squared_length() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] + e[2];
    }

    void make_unit_vector();

    // Data
    float e[3];
};

// Free functions.
std::istream& operator>>(std::istream& stream, vec3& v)
{
    stream >> v[0] >> v[1] >> v[2];
    return stream;
}

std::ostream& operator<<(std::ostream& stream, vec3& v)
{
    stream << "[" << v[0] << ", " << v[1] << ", " << v[2] << "]";
    return stream;
}

inline void vec3::make_unit_vector()
{
    float k = 1.0f / this->length();
    e[0] *= k; e[1] *= k; e[2] *= k;
}

vec3 operator+(const vec3& lhs, const vec3& rhs)
{
    return vec3(lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2]);
}

vec3 operator-(const vec3& lhs, const vec3& rhs)
{
    return vec3(lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2]);
}

// Is this really defined - I guess not for direction vectors but colours yes...
vec3 operator*(const vec3& lhs, const vec3& rhs)
{
    return vec3(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]);
}

vec3 operator/(const vec3& lhs, const vec3& rhs)
{
    return vec3(lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2]);
}

// Multiplication by a scalar
vec3 operator*(float lhs, const vec3& rhs)
{
    return vec3(rhs[0] * lhs, rhs[1] * lhs, rhs[2] * lhs);
}

vec3 operator*(const vec3& lhs, float rhs)
{
    return vec3(lhs[0] * rhs, lhs[1] * rhs, lhs[2] * rhs);
}

// Division by a scalar
vec3 operator/(const vec3& lhs, float rhs)
{
   return vec3(lhs[0] / rhs, lhs[1] / rhs, lhs[2] / rhs);
}

// Returns the signed length of 2 vectors.
//  if they face in the same direction the result will be positive
//  if they face in opositie directions the result will be negative
//  if they are perpendicator the result will be 0.
float dot(const vec3& v1, const vec3& v2)
{
    return (v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]);
}

vec3 cross(const vec3& lhs, const vec3& rhs)
{
    return vec3(lhs[1] * rhs[2] - lhs[2] * rhs[1],
                (-(lhs[0] * rhs[2] - lhs[2] * rhs[0])),
                (lhs[0] * rhs[1] - lhs[1] * rhs[0])
                );
}

vec3& vec3::operator+=(const vec3& rhs)
{
    e[0] += rhs[0];
    e[1] += rhs[1];
    e[2] += rhs[2];

    return *this;
}

vec3& vec3::operator*=(const vec3& rhs)
{
    e[0] *= rhs[0];
    e[1] *= rhs[1];
    e[2] *= rhs[2];

    return *this;
}

vec3& vec3::operator/=(const vec3& rhs)
{
    e[0] /= rhs[0];
    e[1] /= rhs[1];
    e[2] /= rhs[2];

    return *this;
}

vec3& vec3::operator-=(const vec3& rhs)
{
    e[0] -= rhs[0];
    e[1] -= rhs[1];
    e[2] -= rhs[2];

    return *this;
}

vec3& vec3::operator*=(float k)
{
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
    return *this;
}

vec3& vec3::operator/=(float k)
{
    float l = 1.0f / k;
    e[0] *= l;
    e[1] *= l;
    e[2] *= l;

    return *this;
}

// Returns a vector pointing in the same direction as v but of size 1.
// Aka. normalising a vector.
vec3 unit_vector(const vec3& v)
{
    return v / v.length();
}

#endif // VEC3_HPP
