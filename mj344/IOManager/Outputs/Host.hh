/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T21:45:04+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-03T23:14:08+00:00
*/

#ifndef MJ344_HOST_HH_
#define MJ344_HOST_HH_

#include "../../../mbed-os/mbed.h"

#include "AOutput.hh"

class Host: public AOutput {

public:
  Host();
  ~Host();

  void		print(const std::string &);

private:
  Serial	*host;
};

#endif /* !MJ344_HOST_HH_ */
