/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T21:46:16+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-08T18:26:07+00:00
*/

#include <time.h>
#include "Host.hh"

Host::Host() {
	this->host = new Serial(USBTX, USBRX);
}

Host::~Host() {
	if (this->host != NULL) { delete this->host; }
}

void	Host::print(const std::string &str) {
	if (this->host != NULL) {
		this->host->printf("\r%i : %s\n", time (NULL), str.c_str());
	}
}
