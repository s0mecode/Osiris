#pragma once

#include <cstdint>

#include <Config/ConfigVariable.h>
#include <Config/RangeConstrainedVariableParams.h>

#include "AimbotActivationKeys.h"
#include "AimbotParams.h"

namespace aimbot
{

enum class TargetSelectionMode : std::uint8_t {
    ClosestToCrosshair,
    ClosestByDistance
};

enum class AimPoint : std::uint8_t {
    Head,
    Body
};

constexpr auto kActivationKeyIndex = RangeConstrainedVariableParams<std::uint8_t>{
    .min = 0,
    .max = static_cast<std::uint8_t>(kActivationKeyBindings.size() - 1),
    .def = 0
};

CONFIG_VARIABLE(Enabled, bool, true);
CONFIG_VARIABLE_RANGE(ActivationKey, kActivationKeyIndex);
CONFIG_VARIABLE(TargetMode, TargetSelectionMode, TargetSelectionMode::ClosestToCrosshair);
CONFIG_VARIABLE(TargetAimPoint, AimPoint, AimPoint::Head);

CONFIG_VARIABLE_RANGE(MaxTargetNdcDistance, aimbot_params::kMaxTargetNdcDistance);
CONFIG_VARIABLE_RANGE(BaseMouseGain, aimbot_params::kBaseMouseGain);
CONFIG_VARIABLE_RANGE(AdditionalMouseGain, aimbot_params::kAdditionalMouseGain);
CONFIG_VARIABLE_RANGE(MaxMouseStep, aimbot_params::kMaxMouseStep);
CONFIG_VARIABLE_RANGE(MinMouseStep, aimbot_params::kMinMouseStep);

}
