#pragma once
#pragma comment(lib, "pluginsdk.lib")
#include "bakkesmod/plugin/bakkesmodplugin.h"

class OnlineStatusChanger : public BakkesMod::Plugin::BakkesModPlugin
{
private:
    std::shared_ptr<std::string> tempStatus;

public:
	void onLoad() override;
	void onUnload() override;

    void SetStatus();
};
