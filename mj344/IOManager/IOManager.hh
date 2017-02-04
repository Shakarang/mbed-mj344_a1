/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:06:23+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T23:12:27+00:00
*/

#ifndef MJ344_IOMANAGER_HH_
#define MJ344_IOMANAGER_HH_

#include <vector>
#include <string>

#include "Inputs/AInput.hh"
#include "Outputs/AOutput.hh"

class IOManager {

public:
  IOManager();
  ~IOManager();

private:
  std::vector<AInput*>	inputs;
  std::vector<AOutput*>	outputs;

public:
  void					printOnAllOutputs(const std::string &);
};

#endif /* !MJ344_IOMANAGER_HH_ */
