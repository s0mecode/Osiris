#pragma once

#include <Features/Aimbot/AimbotConfigVariables.h>
#include <HookContext/HookContextMacros.h>

template <typename HookContext>
struct AimbotAimPointDropdownSelectionChangeHandler {
    explicit AimbotAimPointDropdownSelectionChangeHandler(HookContext& hookContext) noexcept
        : hookContext{hookContext}
    {
    }

    void onSelectionChanged(int selectedIndex)
    {
        switch (selectedIndex) {
        case 0: SET_CONFIG_VAR(aimbot::TargetAimPoint, aimbot::AimPoint::Head); break;
        case 1: SET_CONFIG_VAR(aimbot::TargetAimPoint, aimbot::AimPoint::Body); break;
        default: break;
        }
    }

private:
    HookContext& hookContext;
};
