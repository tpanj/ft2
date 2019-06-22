#ifndef __FT2_MIDI_H
#define __FT2_MIDI_H

#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>

#define MIDI_INPUT_SELECTOR_BOX_WIDTH 247
#define MAX_MIDI_DEVICES 99

struct midi_t
{
	char *inputDeviceName, *inputDeviceNames[MAX_MIDI_DEVICES];
	volatile bool closeMidiOnExit, initThreadDone;
	uint32_t inputDevice;
	bool enable, rescanDevicesFlag;
	int16_t currMIDIVibDepth, currMIDIPitch;
	int32_t numInputDevices;
} midi;

void closeMidiInDevice(void);
void freeMidiIn(void);
bool initMidiIn(void);
bool openMidiInDevice(uint32_t deviceID);
void recordMIDIEffect(uint8_t effTyp, uint8_t effData);
bool saveMidiInputDeviceToConfig(void);
bool setMidiInputDeviceFromConfig(void);
void freeMidiInputDeviceList(void);
void rescanMidiInputDevices(void);
void drawMidiInputList(void);
void scrollMidiInputDevListUp(void);
void scrollMidiInputDevListDown(void);
void sbMidiInputSetPos(uint32_t pos);
bool testMidiInputDeviceListMouseDown(void);
int32_t SDLCALL initMidiFunc(void *ptr);

#endif
