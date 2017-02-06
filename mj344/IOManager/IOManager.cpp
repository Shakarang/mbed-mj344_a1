/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:24:19+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T22:33:14+00:00
*/

#include "IOManager.hh"

IOManager::IOManager(): bottomLight(Light(Light::FRDM)), topLight(Light(Light::SHIELD)) {
	this->currentSensorIndex = 0;
	this->bottomLight.updateState(Light::BLACK);
	this->topLight.updateState(Light::BLACK);
}

IOManager::~IOManager() {

	for (std::vector<UserInput*>::iterator it = this->userInputs.begin() ; it != this->userInputs.end(); ++it) {
		delete (*it);
	}

	this->userInputs.clear();

	for (std::vector<ASensorInput*>::iterator it = this->sensors.begin() ; it != this->sensors.end(); ++it) {
		delete (*it);
	}

	this->sensors.clear();
}

void 	IOManager::addUserInput(UserInput *input) {
	this->userInputs.push_back(input);
}

void 	IOManager::addSensor(ASensorInput *input) {
	this->sensors.push_back(input);
}

void	IOManager::display(const std::string &str) {
	this->screen.print(str);
}

void	IOManager::log(const std::string &str) {
	this->host.print(str);
}

const std::vector<ASensorInput*>	&IOManager::getSensors() {
	return this->sensors;
}

ASensorInput					*IOManager::getNextSensor() {

	int sensorsLength = this->sensors.size();

	if (sensorsLength == 0) { return NULL; }

	// If we reach the end of the vector, return the first element
	if (this->currentSensorIndex == (sensorsLength - 1)) {
		this->currentSensorIndex = 0;
		return this->sensors[0];
	} else { // Returns the next element
		++this->currentSensorIndex;
		return this->sensors[this->currentSensorIndex];
	}
}

ASensorInput 					*IOManager::getPreviousSensor() {

	int sensorsLength = this->sensors.size();

	if (sensorsLength == 0) { return NULL; }

	// If we reach the beginning of the vector, return the last element
	if (this->currentSensorIndex == 0) {
		this->currentSensorIndex = sensorsLength - 1;
		return this->sensors[sensorsLength - 1];
	} else { // Returns the previous element
		--this->currentSensorIndex;
		return this->sensors[this->currentSensorIndex];
	}
}

Light		&IOManager::getBottomLight() {
	return this->bottomLight;
}

Light		&IOManager::getTopLight() {
	return this->topLight;
}
