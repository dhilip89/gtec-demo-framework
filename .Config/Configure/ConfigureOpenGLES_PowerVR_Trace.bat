@echo off
set FSL_GLES_EMULATOR_PATH=c:\Imagination\PowerVR_Graphics
set FSL_GLES_INCLUDE_PATH=%FSL_GLES_EMULATOR_PATH%\PowerVR_SDK\SDK_2016_R1.2\Builds\Include
set FSL_GLES_LIB_PATH=%FSL_GLES_EMULATOR_PATH%\PowerVR_Tools\PVRVFrame\Library\Windows_x86_64
set FSL_GLES_DLL_PATH=%FSL_GLES_EMULATOR_PATH%\PowerVR_Tools\PVRTrace\Recorder\Windows_x86_64
set FSL_GLES_DLL_ORG_PATH=%FSL_GLES_EMULATOR_PATH%\PowerVR_Tools\PVRTrace\Recorder\Windows_x86_64
set FSL_GLES_LIB_EGL=libEGL.lib
set FSL_GLES_LIB_GLES=libGLESv2.lib
set FSL_GLES_NAME=PowerVR_Trace
set PATH=%FSL_GLES_DLL_PATH%;%PATH%
