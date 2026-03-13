#pragma once

#include <concepts>
#include <cstdint>

#include <GameClient/Panorama/PanoramaDropDown.h>
#include <EntryPoints/GuiEntryPoints.h>
#include <Platform/Macros/FunctionAttributes.h>

#include "Tabs/VisualsTab/IntSlider.h"
#include "AimbotActivationKeyDropdownSelectionChangeHandler.h"
#include "AimbotAimPointDropdownSelectionChangeHandler.h"
#include "AimbotTargetModeDropdownSelectionChangeHandler.h"
#include "OnOffDropdownSelectionChangeHandler.h"

template <typename HookContext>
class CombatTab {
public:
    explicit CombatTab(HookContext& hookContext) noexcept
        : hookContext{hookContext}
    {
    }

    void init(auto&& guiPanel) const
    {
        initDropDown<OnOffDropdownSelectionChangeHandler<HookContext, aimbot::Enabled>>(guiPanel, "aimbot_enabled");
        initDropDown<AimbotActivationKeyDropdownSelectionChangeHandler<HookContext>>(guiPanel, "aimbot_activation_key");
        initDropDown<AimbotTargetModeDropdownSelectionChangeHandler<HookContext>>(guiPanel, "aimbot_target_mode");
        initDropDown<AimbotAimPointDropdownSelectionChangeHandler<HookContext>>(guiPanel, "aimbot_aim_point");
        initDropDown<OnOffDropdownSelectionChangeHandler<HookContext, no_scope_inaccuracy_vis_vars::Enabled>>(guiPanel, "no_scope_inacc_vis");
    }

    void updateFromConfig(auto&& mainMenu) const noexcept
    {
        setDropDownSelectedIndex(mainMenu, "aimbot_enabled", !GET_CONFIG_VAR(aimbot::Enabled));
        setDropDownSelectedIndex(mainMenu, "aimbot_activation_key", static_cast<int>(static_cast<std::uint8_t>(GET_CONFIG_VAR(aimbot::ActivationKey))));
        setDropDownSelectedIndex(mainMenu, "aimbot_target_mode", static_cast<int>(GET_CONFIG_VAR(aimbot::TargetMode)));
        setDropDownSelectedIndex(mainMenu, "aimbot_aim_point", static_cast<int>(GET_CONFIG_VAR(aimbot::TargetAimPoint)));
        updateSlider<aimbot::MaxTargetNdcDistance>(mainMenu, "aimbot_max_target_ndc_distance");
        updateSlider<aimbot::BaseMouseGain>(mainMenu, "aimbot_base_mouse_gain");
        updateSlider<aimbot::AdditionalMouseGain>(mainMenu, "aimbot_additional_mouse_gain");
        updateSlider<aimbot::MaxMouseStep>(mainMenu, "aimbot_max_mouse_step");
        updateSlider<aimbot::MinMouseStep>(mainMenu, "aimbot_min_mouse_step");
        setDropDownSelectedIndex(mainMenu, "no_scope_inacc_vis", !GET_CONFIG_VAR(no_scope_inaccuracy_vis_vars::Enabled));
    }

private:
    template <typename Handler>
    void initDropDown(auto&& guiPanel, const char* panelId) const
    {
        auto&& dropDown = guiPanel.findChildInLayoutFile(panelId).clientPanel().template as<PanoramaDropDown>();
        dropDown.registerSelectionChangedHandler(&GuiEntryPoints<HookContext>::template dropDownSelectionChanged<Handler>);
    }

    [[NOINLINE]] void setDropDownSelectedIndex(auto&& mainMenu, const char* dropDownId, int selectedIndex) const noexcept
    {
        mainMenu.findChildInLayoutFile(dropDownId).clientPanel().template as<PanoramaDropDown>().setSelectedIndex(selectedIndex);
    }

    template <typename ConfigVariable>
    void updateSlider(auto&& mainMenu, const char* sliderId) const noexcept
    {
        updateSlider(mainMenu, sliderId, static_cast<typename ConfigVariable::ValueType::ValueType>(GET_CONFIG_VAR(ConfigVariable)));
    }

    template <std::unsigned_integral IntegerType>
    void updateSlider(auto&& mainMenu, const char* sliderId, IntegerType value) const noexcept
    {
        auto&& slider = hookContext.template make<IntSlider>(mainMenu.findChildInLayoutFile(sliderId));
        slider.updateSlider(value);
        slider.updateTextEntry(value);
    }

    HookContext& hookContext;
};
