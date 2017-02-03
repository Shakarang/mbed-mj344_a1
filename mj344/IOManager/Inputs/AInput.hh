/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T16:46:13+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T17:48:28+00:00
*/

#ifndef MJ344_AINPUT_HH_
#define MJ344_AINPUT_HH_

#include <string>

#include "../../../mbed-os/mbed.h"

class AInput {

public:
  AInput();
  virtual ~AInput() {};

  virtual void triggered() = 0;

protected:
  PinName pinName;
  std::string identifier;
  void (*ptr)(void);
};

#endif /* !MJ344_AINPUT_HH_ */
