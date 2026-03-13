#pragma once

#include <cstdint>

#include <Config/RangeConstrainedVariableParams.h>

namespace aimbot_params
{

constexpr auto kMaxTargetNdcDistance = RangeConstrainedVariableParams<std::uint16_t>{
    .min = 5,
    .max = 250,
    .def = 100
};

constexpr auto kBaseMouseGain = RangeConstrainedVariableParams<std::uint16_t>{
    .min = 10,
    .max = 600,
    .def = 180
};

constexpr auto kAdditionalMouseGain = RangeConstrainedVariableParams<std::uint16_t>{
    .min = 0,
    .max = 800,
    .def = 320
};

constexpr auto kMaxMouseStep = RangeConstrainedVariableParams<std::uint16_t>{
    .min = 1,
    .max = 200,
    .def = 45
};

constexpr auto kMinMouseStep = RangeConstrainedVariableParams<std::uint16_t>{
    .min = 1,
    .max = 200,
    .def = 12
};

[[nodiscard]] constexpr float ndcDistanceFromSlider(std::uint16_t value) noexcept
{
    return static_cast<float>(value) * 0.01f;
}

[[nodiscard]] constexpr float minMouseStepFromSlider(std::uint16_t value) noexcept
{
    return static_cast<float>(value) * 0.01f;
}

}
