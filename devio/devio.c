/* Copyright (C) 2009-2010 Jonathan F. Jao */

#include <jonax/system.h>
#include <jonax/devio.h>
void init_dev()
{
	keyboard_install();
	init_video();
}
