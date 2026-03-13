#pragma once

#include <cstdint>

#include <Features/Aimbot/AimbotConfigVariables.h>
#include <HookContext/HookContextMacros.h>

template <typename HookContext>
struct AimbotActivationKeyDropdownSelectionChangeHandler {
    explicit AimbotActivationKeyDropdownSelectionChangeHandler(HookContext& hookContext) noexcept
        : hookContext{hookContext}
    {
    }

    void onSelectionChanged(int selectedIndex)
    {
        if (selectedIndex < 0 || selectedIndex >= static_cast<int>(aimbot::kActivationKeyBindings.size()))
            return;

        SET_CONFIG_VAR(aimbot::ActivationKey, aimbot::ActivationKey::ValueType{static_cast<std::uint8_t>(selectedIndex)});
    }

private:
    HookContext& hookContext;
};
