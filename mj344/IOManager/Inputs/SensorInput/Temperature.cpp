/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T14:11:11+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T17:10:20+00:00
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

	map[this->units[this->currentUnitIndex]] = this->sensor->read();

	return map;
}
