#pragma once
#include "NWNX4Plugin.h"
class SamplePlugin :
	public NWNX4PluginBase
{
public :
	SamplePlugin () : NWNX4PluginBase("SAMPLE", "EXAMPLE", "1.0.0", "This is a sample plugin that does nothing.")
	{};
};

