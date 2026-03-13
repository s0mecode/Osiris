#pragma once

#include <Features/Aimbot/AimbotConfigVariables.h>
#include <HookContext/HookContextMacros.h>

template <typename HookContext>
struct AimbotTargetModeDropdownSelectionChangeHandler {
    explicit AimbotTargetModeDropdownSelectionChangeHandler(HookContext& hookContext) noexcept
        : hookContext{hookContext}
    {
    }

    void onSelectionChanged(int selectedIndex)
    {
        switch (selectedIndex) {
        case 0: SET_CONFIG_VAR(aimbot::TargetMode, aimbot::TargetSelectionMode::ClosestToCrosshair); break;
        case 1: SET_CONFIG_VAR(aimbot::TargetMode, aimbot::TargetSelectionMode::ClosestByDistance); break;
        default: break;
        }
    }

private:
    HookContext& hookContext;
};
