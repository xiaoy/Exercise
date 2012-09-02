/*
 * LightCommad.h
 *
 *  Created on: 2012-5-22
 *      Author: lfwu
 */

#ifndef LIGHT_ON_COMMAND_H_
#define LIGHT_ON_COMMAND_H_
#include "Light.h"

class LightOnCommand {
public:
	LightOnCommand();
	virtual ~LightOnCommand();
	void SetLight(Light* light);
	void Excute();
private:
	Light* light_;
};

#endif /* LIGHTCOMMAD_H_ */
