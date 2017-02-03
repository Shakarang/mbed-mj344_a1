/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:24:19+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T17:36:46+00:00
*/

#include "IOManager.hh"

IOManager::IOManager() {

}

IOManager::~IOManager() {

  /// Delete all pointers contained in Inputs vector
  for (std::vector<AInput*>::iterator it = this->inputs.begin() ; it != this->inputs.end(); ++it) {
    delete (*it);
  }
  // Clear vector
  this->inputs.clear();

}
