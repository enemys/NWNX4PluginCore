/*++

Copyright (c) Ken Johnson (Skywing). All rights reserved.
Modified in 2020 by enemys.

Module Name:

	NWNX4Plugin.h

Abstract:

	This module defines interfaces related to the NWNX4 plugin API.

--*/

#ifndef NWNX4PLUGIN_H
#define NWNX4PLUGIN_H

#ifdef _MSC_VER
#pragma once
#endif

#define NWNXAPI __thiscall

#include <Windows.h>
#include <strsafe.h>
#include <string>

#define MAX_BUFFER 64*1024

class NWNX4PluginBase
{

public:

	inline
		NWNX4PluginBase(
			__in const char* ClassName,
			__in const char* Subclass,
			__in const char* Version,
			__in const char* Description
		)
		: className(ClassName),
		subclass(Subclass),
		version(Version),
		description(Description)
	{
	}

	inline
		virtual
		NWNXAPI
		~NWNX4PluginBase(
		)
	{
	}

	inline
		virtual
		bool
		NWNXAPI
		Init(
			__in const char* NWNXHome
		)
	{
		nwnxPath = NWNXHome;

		return true;
	}

	inline
		virtual
		int
		NWNXAPI
		GetInt(
			__in const char* Function,
			__in const char* Param1,
			__in int Param2
		)
	{
		UNREFERENCED_PARAMETER(Function);
		UNREFERENCED_PARAMETER(Param1);
		UNREFERENCED_PARAMETER(Param2);

		return 0;
	}

	inline
		virtual
		void
		NWNXAPI
		SetInt(
			__in const char* Function,
			__in const char* Param1,
			__in int Param2,
			__in int Value
		)
	{
		UNREFERENCED_PARAMETER(Function);
		UNREFERENCED_PARAMETER(Param1);
		UNREFERENCED_PARAMETER(Param2);
		UNREFERENCED_PARAMETER(Value);
	}

	inline
		virtual
		float
		NWNXAPI
		GetFloat(
			__in const char* Function,
			__in const char* Param1,
			__in int Param2
		)
	{
		UNREFERENCED_PARAMETER(Function);
		UNREFERENCED_PARAMETER(Param1);
		UNREFERENCED_PARAMETER(Param2);

		return 0.0f;
	}

	inline
		virtual
		void
		NWNXAPI
		SetFloat(
			__in const char* Function,
			__in const char* Param1,
			__in int Param2,
			__in float Value
		)
	{
		UNREFERENCED_PARAMETER(Function);
		UNREFERENCED_PARAMETER(Param1);
		UNREFERENCED_PARAMETER(Param2);
		UNREFERENCED_PARAMETER(Value);
	}

	inline
		virtual
		const char*
		NWNXAPI
		GetString(
			__in const char* Function,
			__in const char* Param1,
			__in int Param2
		)
	{
		UNREFERENCED_PARAMETER(Param1);
		UNREFERENCED_PARAMETER(Param2);

		return ProcessQueryFunction(Function);
	}

	inline
		virtual
		void
		NWNXAPI
		SetString(
			__in const char* Function,
			__in const char* Param1,
			__in int Param2,
			__in const char* Value
		)
	{
		UNREFERENCED_PARAMETER(Function);
		UNREFERENCED_PARAMETER(Param1);
		UNREFERENCED_PARAMETER(Param2);
		UNREFERENCED_PARAMETER(Value);
	}

	inline
		virtual
		void
		NWNXAPI
		GetFunctionClass(
			__out_ecount(128) char* ClassName
		)
	{
		StringCbCopyA(ClassName, 128, className.c_str());
	}

	inline const char* WriteBuffer(const char* value, size_t len = 0)
	{
		if (len == 0)
			len = strlen(value);
		if (len > MAX_BUFFER)
			len = MAX_BUFFER;

		memcpy(buffer, value, len);
		buffer[len - 1] = 0x0;
		return buffer;
	}

protected:

	inline
		const char*
		ProcessQueryFunction(
			__in const char* QueryFunction
		)
	{
		if (!strcmp(QueryFunction, "GET SUBCLASS"))
			return subclass.c_str();
		else if (!strcmp(QueryFunction, "GET VERSION"))
			return version.c_str();
		else if (!strcmp(QueryFunction, "GET DESCRIPTION"))
			return description.c_str();
		else
			return "";
	}

	std::string className;
	std::string subclass;
	std::string version;
	std::string description;
	std::string nwnxPath;
	char buffer[MAX_BUFFER] = { 0 };

};

NWNX4PluginBase*
WINAPI
GetPluginPointerV2(
);

#endif
