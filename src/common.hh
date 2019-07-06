#ifndef COMMON_HH
#define COMMON_HH

#define unpack3(vec3) vec3.x, vec3.y, vec3.z
#define unpack2(vec2) vec2.x, vec2.y

template <typename T>
struct vec3{
    T x, y, z;
};

template <typename T>
struct vec2{
    T x, y;
};

typedef vec3<float> vec3f;
typedef vec3f color3f;

typedef vec2<float> vec2f;
typedef vec2f coord2D;

typedef struct Line_t {
    coord2D pos1;
    coord2D pos2;
} Line;

#endif