#include "base.h"
#include "Light.h"
#include "LightOnCommand.h"
int main() {
	Light* light = new Light;
	LightOnCommand *light_on_command = new LightOnCommand;
	light_on_command->SetLight(light);
	light_on_command->Excute();
	delete light_on_command;
	delete light;
}
