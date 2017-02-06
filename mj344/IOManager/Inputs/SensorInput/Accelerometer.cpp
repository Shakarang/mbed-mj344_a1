/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-06T15:51:40+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-06T17:21:20+00:00
*/

#include "Accelerometer.hh"

Accelerometer::Accelerometer(): ASensorInput(ASensorInput::ACCELEROMETER) {
	this->sensor = new MMA7660(D14, D15);
	this->units.push_back("Degrees");
	this->units.push_back("-");
}

Accelerometer::~Accelerometer() {
	if (this->sensor != NULL) { delete this->sensor; }
}

std::map<std::string, float>	Accelerometer::getData() const {

	std::map<std::string, float> map;

	map["x"] = roundf(this->sensor->x() * 100) / 100.0;
	map["y"] = roundf(this->sensor->y() * 100) / 100.0;
	map["z"] = roundf(this->sensor->z() * 100) / 100.0;



	// float data = this->sensor->read();
	//
	// switch (this->currentUnitIndex) {
	// 	case 0: // Celsius
	// 	map[this->units[this->currentUnitIndex]] = data;
	// 	break;
	// 	case 1: // Fahrenheit
	// 	map[this->units[this->currentUnitIndex]] = (data * 1.8 + 32);
	// 	break;
	// 	case 2: // Kelvin
	// 	map[this->units[this->currentUnitIndex]] = (data + 273.15);
	// 	break;
	// }

	return map;
}
