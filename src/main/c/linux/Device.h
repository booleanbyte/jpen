/* [{
Copyright 2007, 2008 Nicolas Carranza <nicarran at gmail.com>

This file is part of jpen.

jpen is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License,
or (at your option) any later version.

jpen is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with jpen.  If not, see <http://www.gnu.org/licenses/>.
}] */
#ifndef Device_h
#define Device_h
#include "macros.h"
#include <X11/extensions/XInput.h>
#include "Bus.h"

enum{
	E_EventType_ButtonPress,
	E_EventType_ButtonRelease,
	E_EventType_MotionNotify,
	E_EventType_ProximityIn,
	E_EventType_ProximityOut,
	E_EventType_size
};
/* Warning: this enumeration is analogous to the PLevel.Type enumeration. */
enum {
	E_Valuators_x,
	E_Valuators_y,
	E_Valuators_press,
	E_Valuators_tiltx,
	E_Valuators_tilty,
	E_Valuators_wheel,
	E_Valuators_size,
};

struct Device {
	int cellIndex;
	int busCellIndex;
	int index;
	XDevice *pXdevice;
	int isListening;
	
	int absoluteMode; // 1 if true, 0 otherwise 
	int valuatorRangeMins[E_Valuators_size];
	int valuatorRangeMaxs[E_Valuators_size];

	int valuatorValues[E_Valuators_size];
	int eventTypeIds[E_EventType_size];
	XEvent lastEvent;
	int lastEventType;
	Time lastEventTime;
	int lastEventButton;
	unsigned int lastEventDeviceState;
	int lastEventProximity;
};
m_declareRow(Device);
extern int Device_init(SDevice *pDevice, SBus *pBus, int deviceIndex);
extern int Device_nextEvent(SDevice *pDevice);
extern int Device_waitNextEvent(SDevice *pDevice);
extern void Device_stopWaitingNextEvent(SDevice *pDevice);
extern void Device_refreshValuatorRanges(SDevice *pDevice);
extern void Device_setIsListening(SDevice *pDevice, int isListening);

#endif

