/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T14:00:45+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T18:05:04+00:00
*/

#include "ASensorInput.hh"

ASensorInput::ASensorInput(const ASensorInput::Type tp): type(tp) {
	this->currentUnitIndex = 0;
}

ASensorInput::Type	ASensorInput::getType() const {
	return this->type;
}

std::string						ASensorInput::getTypeReadable() const {
	switch (this->type) {
		case ASensorInput::ACCELEROMETER: return "Accelerometer";
		case ASensorInput::TEMPERATURE: return "Temperature";
	}
	return "";
}

const std::vector<std::string>	&ASensorInput::getUnits() const {
	return this->units;
}

const std::string				ASensorInput::getCurrentUnit() const {
	return this->units[this->currentUnitIndex];
}

int								ASensorInput::getCurrentUnitIndex() const {
	return this->currentUnitIndex;
}

const std::string				ASensorInput::getNextUnit() {

	int unitsLength = this->units.size();

	if (unitsLength == 0) { return ""; }

	// If we reach the end of the vector, return the first element
	if (this->currentUnitIndex == (unitsLength - 1)) {
		this->currentUnitIndex = 0;
		return this->units[0];
	} else { // Returns the next element
		++this->currentUnitIndex;
		return this->units[this->currentUnitIndex];
	}
}

const std::string 				ASensorInput::getPreviousUnit() {

	int unitsLength = this->units.size();

	if (unitsLength == 0) { return ""; }

	// If we reach the beginning of the vector, return the last element
	if (this->currentUnitIndex == 0) {
		this->currentUnitIndex = unitsLength - 1;
		return this->units[unitsLength - 1];
	} else { // Returns the previous element
		--this->currentUnitIndex;
		return this->units[this->currentUnitIndex];
	}
}
