/**
* @Author: Maxime Junger <mj344>
* @Date:   2017-02-03T17:06:23+00:00
* @Email:  mj344@kent.ac.uk
* @Last modified by:   mj344
* @Last modified time: 2017-02-04T15:39:13+00:00
*/

#ifndef MJ344_IOMANAGER_HH_
#define MJ344_IOMANAGER_HH_

#include <vector>
#include <string>

#include "Outputs/AOutput.hh"
#include "Inputs/UserInput/UserInput.hh"

#include "Outputs/Host.hh"
#include "Outputs/Screen.hh"

class IOManager {

public:
  IOManager();
  ~IOManager();

private:
  std::vector<UserInput*>	userInputs;
  //std::vector<AOutput*>		outputs;
  
  Screen 					screen;
  Host 						host;

public:
  void						display(const std::string &);
  void						log(const std::string &);
};

#endif /* !MJ344_IOMANAGER_HH_ */
