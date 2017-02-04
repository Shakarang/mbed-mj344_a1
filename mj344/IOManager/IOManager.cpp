/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:24:19+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T23:14:12+00:00
*/

#include "IOManager.hh"

#include "Outputs/Host.hh"
#include "Outputs/Screen.hh"

IOManager::IOManager() {

	this->outputs.push_back(new Host());
	this->outputs.push_back(new Screen());

}

IOManager::~IOManager() {

  for (std::vector<AInput*>::iterator it = this->inputs.begin() ; it != this->inputs.end(); ++it) {
	delete (*it);
  }

  this->inputs.clear();

  for (std::vector<AOutput*>::iterator it = this->outputs.begin() ; it != this->outputs.end(); ++it) {
	delete (*it);
  }

  this->outputs.clear();

}

void	IOManager::printOnAllOutputs(const std::string &str) {
	for (std::vector<AOutput*>::iterator it = this->outputs.begin() ; it != this->outputs.end(); ++it) {
	  (*it)->print(str);
	}
  }
