/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:57:51+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T21:11:13+00:00
*/


#ifndef MJ344_SCREEN_HH_
#define MJ344_SCREEN_HH_

#include "../../../mbed-os/mbed.h"
#include "../../../C12832/C12832.h"

#include "AOutput.hh"

class Screen: protected AOutput {

public:
  Screen();
  ~Screen();

  void print(const std::string &);

private:
  /**
   * LCD value for
   */
  C12832 *shieldLCD;
};

#endif /* !MJ344_SCREEN_HH_ */
