#pragma once

#ifdef FF_PLATFORM_WINDOWS
	#ifdef FF_BUILD_DLL 
		#define FIREFLY_API __declspec(dllexport)
	#else  
		#define FIREFLY_API __declspec(dllimport)
	#endif
#else
	#error Firefly doesnt support this platform
#endif
