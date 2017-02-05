/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T17:17:29+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T20:14:33+00:00
*/

#include "ServiceManager.hh"

#include "IOManager/Inputs/UserInput/Switch.hh"
#include "IOManager/Inputs/UserInput/Joystick.hh"

#include "IOManager/Inputs/SensorInput/Temperature.hh"

ServiceManager::ServiceManager() {

	this->iomanager.addUserInput(new Switch(SW2, callback(this, &ServiceManager::pauseHandler)));
	this->iomanager.addUserInput(new Joystick(callback(this, &ServiceManager::joystickHandler)));

	this->iomanager.addSensor(new Temperature());
	this->currentSensor = this->iomanager.getSensors()[0];
}

ServiceManager::~ServiceManager() {

}

void ServiceManager::start() {

	// Here is the while with the rate to wait data

}

void	ServiceManager::pauseHandler(const UserInput::Type it) {

}

void ServiceManager::joystickHandler(const UserInput::Type input) {

	switch (input) {
		case UserInput::FIRE:
		this->iomanager.display("FIRE");
		break;
		case UserInput::LEFT:
		if (this->currentSensor != NULL) {
			this->iomanager.display(this->currentSensor->getPreviousUnit());
		}
		break;
		case UserInput::RIGHT:
		if (this->currentSensor != NULL) {
			this->iomanager.display(this->currentSensor->getNextUnit());
		}
		break;
		case UserInput::UP:
		if ((this->currentSensor = this->iomanager.getPreviousSensor()) != NULL) {
			this->iomanager.display(this->currentSensor->getTypeReadable());
		}
		break;
		case UserInput::DOWN:
		this->iomanager.display("DOWN");
		break;
	}

}
