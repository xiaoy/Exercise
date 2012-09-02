/*
 * LightCommad.cc
 *
 *  Created on: 2012-5-22
 *      Author: lfwu
 */

#include "LightOnCommand.h"
#include "base.h"
LightOnCommand::LightOnCommand() {
	// TODO Auto-generated constructor stub

}

LightOnCommand::~LightOnCommand() {
	// TODO Auto-generated destructor stub
}

void LightOnCommand::SetLight(Light* light) {
	light_ = light;
}

void LightOnCommand::Excute() {
	if(light_ != NULL) {
		light_->LightOn();
	}
}
