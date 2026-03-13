#pragma once

#include <Platform/Macros/IsPlatform.h>

#if IS_WIN64()

#include <windows.h>

#include "WindowsDynamicLibrary.h"

#endif

class WindowsInput {
public:
    void moveMouseRelative(float deltaX, float deltaY) noexcept
    {
#if IS_WIN64()
        if (!sendInput)
            sendInput = WindowsDynamicLibrary{"user32.dll"}.getFunctionAddress("SendInput").as<decltype(&::SendInput)>();
        if (!sendInput)
            return;

        subPixelRemainderX += deltaX;
        subPixelRemainderY += deltaY;

        const auto integerDeltaX = roundToInt(subPixelRemainderX);
        const auto integerDeltaY = roundToInt(subPixelRemainderY);
        subPixelRemainderX -= static_cast<float>(integerDeltaX);
        subPixelRemainderY -= static_cast<float>(integerDeltaY);

        if (integerDeltaX == 0 && integerDeltaY == 0)
            return;

        INPUT input{};
        input.type = INPUT_MOUSE;
        input.mi.dx = integerDeltaX;
        input.mi.dy = integerDeltaY;
        input.mi.dwFlags = MOUSEEVENTF_MOVE;
        sendInput(1, &input, sizeof(INPUT));
#else
        static_cast<void>(deltaX);
        static_cast<void>(deltaY);
#endif
    }

private:
#if IS_WIN64()
    [[nodiscard]] static int roundToInt(float value) noexcept
    {
        return static_cast<int>(value >= 0.0f ? value + 0.5f : value - 0.5f);
    }

    decltype(&::SendInput) sendInput{
        WindowsDynamicLibrary{"user32.dll"}.getFunctionAddress("SendInput").as<decltype(&::SendInput)>()
    };
    float subPixelRemainderX{0.0f};
    float subPixelRemainderY{0.0f};
#endif
};
