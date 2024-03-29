/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T17:17:29+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T19:26:24+00:00
*/

#include <sstream>

#include "ServiceManager.hh"

#include "IOManager/Inputs/UserInput/Switch.hh"
#include "IOManager/Inputs/UserInput/Joystick.hh"

#include "IOManager/Inputs/SensorInput/Temperature.hh"
#include "IOManager/Inputs/SensorInput/Accelerometer.hh"

ServiceManager::ServiceManager() {

	this->iomanager.addUserInput(new Switch(SW3, callback(this, &ServiceManager::resumeHandler)));
	this->iomanager.addUserInput(new Switch(SW2, callback(this, &ServiceManager::updateRateHandler)));
	this->iomanager.addUserInput(new Joystick(callback(this, &ServiceManager::joystickHandler)));

	this->iomanager.addSensor(new Temperature());
	this->iomanager.addSensor(new Accelerometer());
	this->currentSensor = this->iomanager.getSensors()[0];

	this->rate = SERVICE_MAXIMAL_RATE;
	this->isRunning = false;
}

ServiceManager::~ServiceManager() {
	if (this->ticker != NULL) { delete this->ticker; }
}

void			ServiceManager::start() {

	this->iomanager.log("Start, new ticker");

	this->isRunning = true;
	this->iomanager.getBottomLight().updateState(Light::GREEN);

	this->ticker = new Ticker();
	this->ticker->attach(callback(this, &ServiceManager::tickerHandler), this->rate);
	this->shouldDisplayData = true;
}

void			ServiceManager::stop() {

	this->iomanager.log("Stop, will kill ticker");
	this->iomanager.display("STOP");

	this->isRunning = false;
	this->iomanager.getBottomLight().updateState(Light::YELLOW);

	if (this->ticker != NULL) {
		delete this->ticker;
		this->ticker = NULL;
	}

}

void			ServiceManager::resumeHandler(const UserInput::Type) {
	if (this->isRunning) {
		this->stop();
	} else {
		this->start();
	}
}

void			ServiceManager::updateRateHandler(const UserInput::Type input) {

	this->shouldDisplayData = false;

	if (this->rate >= SERVICE_MINIMAL_RATE) {
		this->rate = SERVICE_MAXIMAL_RATE;
	} else {
		this->rate += SERVICE_RATE_STEP;
	}

	ostringstream oss;

	oss << "New rate : " << this->rate << std::endl;
	// Update ticker if exists
	if (this->ticker != NULL) {
		this->ticker->attach(callback(this, &ServiceManager::tickerHandler), this->rate);
	}
	this->iomanager.display(oss.str());
}

void			ServiceManager::joystickHandler(const UserInput::Type input) {


	this->iomanager.log("User interracted with the Joystick");

	// If the application is in pause, we don't accept
	// other joystick input than the FIRE (to validate options).
	if (this->isRunning == false && input != UserInput::FIRE) {
		return;
	}

	// User in interracting, he should not see the data appearing on LCD
	this->shouldDisplayData = false;

	this->iomanager.getTopLight().updateState(Light::BLACK);

	switch (input) {
		case UserInput::FIRE: // Re-enabling data on display if the menu was on screen.
			this->shouldDisplayData = true;
			this->tickerHandler();
		break;
		case UserInput::LEFT: // Get previout unit of the current sensor
		if (this->currentSensor != NULL) {
			this->iomanager.display(this->currentSensor->getPreviousUnit());
		}
		break;
		case UserInput::RIGHT: // Get the next unit of the current sensor
		if (this->currentSensor != NULL) {
			this->iomanager.display(this->currentSensor->getNextUnit());
		}
		break;
		case UserInput::UP: // Previous sensor
		if ((this->currentSensor = this->iomanager.getPreviousSensor()) != NULL) {
			this->iomanager.display(this->currentSensor->getTypeReadable());
		}
		break;
		case UserInput::DOWN: // Next sensor
		if ((this->currentSensor = this->iomanager.getNextSensor()) != NULL) {
			this->iomanager.display(this->currentSensor->getTypeReadable());
		}
		break;
	}

}

void			ServiceManager::tickerHandler() {

	this->iomanager.log("Ticker handler");

	if (this->currentSensor != NULL) {
		std::map<std::string, float> data = this->currentSensor->getData();
		switch (this->currentSensor->getType()) {
			case ASensorInput::TEMPERATURE:
			this->temperatureHandler(data);
			break;
			case ASensorInput::ACCELEROMETER:
			this->accelerometerHandler(data);
			break;
		}
	}

}

void			ServiceManager::temperatureHandler(std::map<std::string, float> data) {

	std::ostringstream stringStream;
	std::ostringstream logStringStream;

	for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); ++it) {
		stringStream << (*it).first << " : " << (*it).second << std::endl;
	}
	if (this->shouldDisplayData) {
		this->iomanager.display(stringStream.str());
	}
	this->iomanager.log(stringStream.str());
}

void			ServiceManager::accelerometerHandler(std::map<std::string, float> data) {

	std::ostringstream stringStream;
	std::ostringstream logStringStream;

	switch (this->currentSensor->getCurrentUnitIndex()) {
		case 0:// Degrees : Roll & Pitch
		this->iomanager.getTopLight().updateState((Light::Color)this->accelerometerColor(data["Pitch"], data["Roll"]));
		stringStream << "Roll : " << data["Roll"] << "\nPitch : " << data["Pitch"] << std::endl;
		break;
		case 1: // Raw
		stringStream << "X : " << data["x"] << "\nY : " << data["y"] << "\nZ : " << data["z"] << std::endl;
		break;
	}

	if (this->shouldDisplayData) {
		this->iomanager.display(stringStream.str());
	}

	for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); ++it) {
		logStringStream << (*it).first << " : " << (*it).second << " ";
	}

	logStringStream << std::endl;

	this->iomanager.log(logStringStream.str());
}

int	ServiceManager::accelerometerColor(float pitch, float roll) {

	// Error range degrees
	float range = 5;

	int result = 4; // To, at least, have the R bit on to never have black light

	if ((pitch >= -range && pitch <= range)
		&& (roll >= -range && roll <= range)) {// Aligned with error range
		return 3; // Corresponding to Light blue, a color that could never happend.
	} else {
		result |= (pitch > 0) << 1; // Setting Green
		result |= (roll > 0) << 0; // Setting Blue;
	 }
	return result;
}
