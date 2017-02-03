/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:06:23+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T17:38:19+00:00
*/

#ifndef MJ344_IOMANAGER_HH_
#define MJ344_IOMANAGER_HH_

#include <vector>

#include "Inputs/AInput.hh"

class IOManager {

public:
  IOManager();
  ~IOManager();



private:
  std::vector<AInput*> inputs;
};

#endif /* !MJ344_IOMANAGER_HH_ */
