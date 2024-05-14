# wrap_dll example

This is an example usage of my [fork of wrap_dll](https://github.com/KodyJKing/wrap_dll).

It wraps `xinput1_3.dll`, hooking the `XInputGetState` function and inverting the analog sticks.

### Building

First make sure you have MSBuild on your path. For me it's under  `C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin`

Then run:
```bat
setup.bat
wrapdll.bat
```

If it worked you should find a wrapped `xinput1_3.dll` under `build/xinput1_3/Debug`.