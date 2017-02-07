/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T14:11:11+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-07T22:27:03+00:00
*/

#include "Temperature.hh"

Temperature::Temperature(): ASensorInput(ASensorInput::TEMPERATURE) {
	this->sensor = new LM75B(I2C_SDA, I2C_SCL);
	this->units.push_back("Celsius");
	this->units.push_back("Fahrenheit");
	this->units.push_back("Kelvin");
}

Temperature::~Temperature() {
	if (this->sensor != NULL) { delete this->sensor; }
}

std::map<std::string, float>	Temperature::getData() const {

	std::map<std::string, float> map;

	float data = this->sensor->read();

	switch (this->currentUnitIndex) {
		case 0: // Celsius
		map[this->units[this->currentUnitIndex]] = data;
		break;
		case 1: // Fahrenheit
		map[this->units[this->currentUnitIndex]] = (data * 1.8 + 32);
		break;
		case 2: // Kelvin
		map[this->units[this->currentUnitIndex]] = (data + 273.15);
		break;
	}

	return map;
}
