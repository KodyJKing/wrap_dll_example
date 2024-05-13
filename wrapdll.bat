copy C:\\Windows\\system32\\xinput1_3.dll .\\bin\\xinput1_3.dll
python wrap_dll/wrap_dll.py --hook hook.h --out build/xinput1_3 --force bin/xinput1_3.dll
cd build/xinput1_3
cmake CMakeLists.txt
MSBuild xinput1_3.sln /p:Platform=x64
cd ..
