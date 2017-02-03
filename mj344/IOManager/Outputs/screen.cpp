/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T18:03:41+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T21:17:01+00:00
*/

#include "Screen.hh"

Screen::Screen(): AOutput("shield_lcd") {
  this->shieldLCD = new C12832(D11, D13, D12, D7, D10);
}

Screen::~Screen() {
  if (this->shieldLCD != NULL) {
    delete this->shieldLCD;
  }
}

void Screen::print(const std::string &str) {
  if (this->shieldLCD != NULL) {
    this->shieldLCD->locate(0, 0);
    this->shieldLCD->printf("%s\n", str.c_str());
  }
}
