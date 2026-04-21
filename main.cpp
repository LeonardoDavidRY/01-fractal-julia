#include <SFML/Graphics.hpp>
#include <complex>
#include <fmt/core.h>
#include "fractal_serial.h"

#ifdef _WIN32
#include <windows.h>
#endif
// Dimension imagen:
#define WIDTH 1600
#define HEIGHT 900
// Parametros:
int max_iterations = 10;
double x_min = -1.5;
double x_max = 1.5;
double y_min = -1.0;
double y_max = 1.0;
std::complex<double> c(-0.7, 0.27015);
// Textura
uint32_t *pixel_buffer = nullptr;
int main() {
  pixel_buffer = new uint32_t[WIDTH * HEIGHT];

  sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "Julia Set - SFML");

#ifdef _WIN32
  HWND hwnd = window.getNativeHandle();
  ShowWindow(hwnd, SW_MAXIMIZE);
#endif
  sf::Texture texture({WIDTH, HEIGHT});
  sf::Sprite sprite(texture);
  sf::Font font("arial.ttf");
  sf::Text text(font, "Julia-Set", 24);

  sf::Clock clock;
  int frames = 0;
  int fps = 0;


    while (window.isOpen()) {
    while (const auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      
    }
    //dibujar
    julia_serial1(x_min, y_min, x_max, y_max, WIDTH, HEIGHT, pixel_buffer);
    texture.update((const uint8_t *)pixel_buffer);

    //contar FPS
    frames++;
    if(clock.getElapsedTime().asSeconds()>= 1.0f){
      fps = frames;
      frames = 0;
      clock.restart();
    }

    window.clear();
    {
      window.draw(sprite);
      window.draw(text);
    }
    window.display();
  }
  delete[] pixel_buffer;
  return 0;
}