/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-06T15:51:40+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-07T22:26:34+00:00
*/

#include <cmath>

#include "Accelerometer.hh"

Accelerometer::Accelerometer(): ASensorInput(ASensorInput::ACCELEROMETER) {
	this->sensor = new MMA7660(D14, D15);
	this->units.push_back("Degrees");
	this->units.push_back("Raw");
}

Accelerometer::~Accelerometer() {
	if (this->sensor != NULL) { delete this->sensor; }
}


/**
 * http://stackoverflow.com/questions/3755059/3d-accelerometer-calculate-the-orientation
 */
std::map<std::string, float>	Accelerometer::getData() const {

	std::map<std::string, float> map;

	map["x"] = roundf(this->sensor->x() * 100) / 100.0;
	map["y"] = roundf(this->sensor->y() * 100) / 100.0;
	map["z"] = roundf(this->sensor->z() * 100) / 100.0;


	map["Roll"] = atan2f(map["y"], map["z"]) * 180/M_PI;
	map["Pitch"] = atan2(-map["x"], sqrt(map["y"] * map["y"] + map["z"] * map["z"])) * 180 / M_PI;

	return map;
}
