#include "fractal_simd.h"
#include "palette.h"
#include <complex>

#include <string>
#include <cstring>

#include <immintrin.h> //avx2 -> 8 valores float 

extern int max_iteraciones;
extern std::complex<double> c;

void julia_simd(double x_min, double y_min, double x_max, double y_max, uint32_t width, uint32_t height, uint32_t *pixel_buffer){
    std::memset(pixel_buffer, 0xFF000000,width*height*sizeof(uint32_t));
    double dx = (x_max - x_min) / width;
    double dy = (y_max - y_min) / height;

    //(xmin. xmin, xmin, xmin, xmin, xmin, xmin, xmin)
    // (-1.5, -1.5, -1.5, -1.5, -1.5, -1.5, -1.5)
    __m256 xmin = _mm256_set1_ps(x_min);
    __m256 ymin = _mm256_set1_ps(y_max);
    __m256 dx_vec = _mm256_set1_ps(dx);
    __m256 dy_vec = _mm256_set1_ps(dy);
    __m256 cr = _mm256_set1_ps(c.real());
    __m256 ci = _mm256_set1_ps(c.imag());

}