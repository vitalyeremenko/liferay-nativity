/**
 * Copyright (c) 2000-2012 Liferay, Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 */ 
#include "logger.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef ENABLE_LOG

void writeLog(const char* format, ...)
{
	va_list args;
	FILE* file = NULL;
	va_start (args, format);
	
	file = fopen("/home/user/LiferayPlugin.log","a+");	
	
	if (file)
	{
		vfprintf (file, format, args);
		fclose(file);
	}
	
	va_end (args); 
}


#else

void writeLog(const char* format, ...)
{
}

#endif
