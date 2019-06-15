#ifndef ARCADE_VECTOR_
#define ARCADE_VECTOR_

/*!
     *  \brief Stock 4 variables
     *
     *  Struct Vector to stock 4 variables
*/
template <typename T>
struct Vector4
{
    T x;
    T y;
    T w;
    T h;
    Vector4(T a=0, T b=0, T c=0, T d=0) : x(a), y(b), w(c), h(d) {}
};

/*!
     *  \brief Stock 2 variables
     *
     *  Struct Vector to stock 2 variables
*/
template <typename T>
struct Vector2
{
    T x;
    T y;
    Vector2(T a=0, T b=0) : x(a), y(b) {}
};

#endif // ARCADE_VECTOR_
