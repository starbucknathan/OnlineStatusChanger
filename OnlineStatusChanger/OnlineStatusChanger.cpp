#include "OnlineStatusChanger.h"
#include "bakkesmod\wrappers\includes.h"

BAKKESMOD_PLUGIN(OnlineStatusChanger, "Plugin to manage online status setting", "1.0", PLUGINTYPE_FREEPLAY)

/*

    If you try linking "cl_online_status_override" to a textbox directly, the game will crash.
    This plugin is a bridge for that.
    You can set your intended message in the textbox, then click Apply when you are ready and it will transfer the temporary cvar into the final cvar.

*/

void OnlineStatusChanger::onLoad()
{
    tempStatus = std::make_shared<std::string>("");
    cvarManager->registerCvar("OnlineStatus_Temporary", "BM Status", "The temporary status stored before being applied to online status cvar", true).bindTo(tempStatus);
    cvarManager->registerNotifier("OnlineStatus_SetStatus", [this](std::vector<std::string> params){SetStatus();}, "Applies the temporary status to the online status cvar", PERMISSION_ALL);
}
void OnlineStatusChanger::onUnload() {}

void OnlineStatusChanger::SetStatus()
{
    cvarManager->getCvar("cl_online_status_override").setValue(*tempStatus);
}
