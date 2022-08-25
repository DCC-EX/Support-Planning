// Minimal myHal.cpp file used for regression testing of Turntable-EX.

#if !defined(IO_NO_HAL)

#include "IODevice.h"
#include "IO_TurntableEX.h"

void halSetup() {
  TurntableEX::create(600, 1, 0x60);
}

#endif
