# wrap_dll example

This example wraps `xinput1_3.dll` to hook the `XInputGetState` function and invert the analog sticks.

### Building

First make sure you have MSBuild on your path. For me it's under  `C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin`

Then run:
```bat
setup.bat
wrapdll.bat
```

If it worked you should find a wrapped `xinput1_3.dll` under `build/xinput1_3/Debug`.