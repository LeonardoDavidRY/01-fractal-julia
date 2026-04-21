#ifndef FRACTAL_SERIAL_H
#define FRACTAL_SERIAL_H

#include <cstdint>
void julia_serial1(double x_min, double x_max, double y_min, double y_max, uint32_t width, uint32_t height, uint32_t *pixel_buffer);

void julia_serial2(double x_min, double x_max, double y_min, double y_max, uint32_t width, uint32_t height, uint32_t *pixel_buffer);

#endif 