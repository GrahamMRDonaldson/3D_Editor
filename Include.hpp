#pragma once
#include <iostream>
#include <windows.h>

#include <string>

#include "Imgui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "Imgui/imgui_impl_dx9.h"
#include "Imgui/imgui_impl_win32.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

#pragma comment(lib,"d3d9.lib")
#pragma warning(disable:4996)

#include <vector>
#include <TlHelp32.h>
#include <algorithm>
#include "CustomCode.h"