/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:24:19+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T11:45:38+00:00
*/

#include "IOManager.hh"

IOManager::IOManager() {

	// this->outputs.push_back(new Host());
	// this->outputs.push_back(new Screen());

}

IOManager::~IOManager() {

	for (std::vector<UserInput*>::iterator it = this->userInputs.begin() ; it != this->userInputs.end(); ++it) {
		delete (*it);
	}

	this->userInputs.clear();
}

void	IOManager::display(const std::string &str) {
	this->screen.print(str);
}


void	IOManager::log(const std::string &str) {
	this->host.print(str);
}
