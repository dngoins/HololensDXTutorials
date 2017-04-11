#pragma once

#include "Common.h"

namespace Library
{
	class ServiceContainer
	{
	public:
		ServiceContainer();
		ServiceContainer(const ServiceContainer& rhs) = delete;
		ServiceContainer& operator=(const ServiceContainer& rhs) = delete;

		void AddService(UINT typeID, void* service);
		void RemoveService(UINT typeID);
		void* GetService(UINT typeID) const;

		std::map<UINT, void*> mServices;
	};
}