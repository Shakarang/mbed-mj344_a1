/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-05T13:21:26+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-05T14:21:16+00:00
*/

#ifndef MJ344_TEMPERATURE_HH_
#define MJ344_TEMPERATURE_HH_

#include "ASensorInput.hh"
#include "../../../../LM75B/LM75B.h"

class Temperature: public ASensorInput {

public:
	Temperature();
	~Temperature();

	std::map<std::string, float>	getData() const;
private:
	LM75B	*sensor;
};

#endif /* !MJ344_TEMPERATURE_HH_ */
