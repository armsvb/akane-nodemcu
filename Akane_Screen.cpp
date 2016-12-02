#include "Akane_Screen.h"

Akane_Screen::Akane_Screen() {
  tft = new Adafruit_ILI9341(TFT_CS, TFT_DC);
  tft->setFont(&FreeSans9pt7b);
}

void Akane_Screen::initialize() { 
  tft->begin();
  tft->setRotation(TFT_ROTATE);
}

void Akane_Screen::set_backgroundcolor(unsigned int color) {
  tft->fillScreen(color);
}

void Akane_Screen::set_foregroundcolor(unsigned int color) {
  tft->setTextColor(color);
}

void Akane_Screen::draw_panel(unsigned int pos) {
  tft->fillRect(0, 100, 320, 50, SCREEN_PANELCOLOR);

  tft->fillRect(0, 190, 320, 50, SCREEN_PANELCOLOR);
}

void Akane_Screen::print_str(const String &txt, unsigned int size, unsigned int x, unsigned int y) {
  tft->setCursor(x, y);
  this->print_str(txt, size);
}

void Akane_Screen::print_str(const String &txt, unsigned int size) {
  tft->setTextSize(size);
  tft->println(txt);
}
