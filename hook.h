/*
 * content of file: hook.h
 */
#include "hook_macro.h"

#include <windows.h>

typedef struct _XINPUT_GAMEPAD {
    WORD  wButtons;
    BYTE  bLeftTrigger;
    BYTE  bRightTrigger;
    SHORT sThumbLX;
    SHORT sThumbLY;
    SHORT sThumbRX;
    SHORT sThumbRY;
} XINPUT_GAMEPAD, * PXINPUT_GAMEPAD;

typedef struct _XINPUT_STATE {
    DWORD          dwPacketNumber;
    XINPUT_GAMEPAD Gamepad;
} XINPUT_STATE, * PXINPUT_STATE;

void flip( short& value ) {
    int ivalue = (int) value;
    ivalue *= -1;
    if ( ivalue < -32768 )
        ivalue = -32768;
    if ( ivalue > 32767 )
        ivalue = 32767;
    value = (short) ivalue;
}

// Tell wrap_dll to hook XInputGetState:
#define XINPUTGETSTATE
FAKE( DWORD, __stdcall, XInputGetState, DWORD dwUserIndex, XINPUT_STATE* pState ) {
    auto result = XInputGetState_real( dwUserIndex, pState );
    flip( pState->Gamepad.sThumbLX );
    flip( pState->Gamepad.sThumbLY );
    flip( pState->Gamepad.sThumbRX );
    flip( pState->Gamepad.sThumbRY );
    return result;
}