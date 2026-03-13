#pragma once

#include <concepts>
#include <cstdint>

#include <GameClient/Panorama/PanoramaUiPanel.h>
#include <GameClient/Panorama/Slider.h>
#include <Utils/StringBuilder.h>

template <typename HookContext>
class IntSlider {
public:
    IntSlider(HookContext& hookContext, cs2::CUIPanel* _panel) noexcept
        : hookContext{hookContext}
        , _panel{_panel}
    {
    }

    template <std::unsigned_integral IntegerType>
    void updateSlider(IntegerType value) const noexcept
    {
        panel().children()[0].clientPanel().template as<Slider>().setValue(static_cast<float>(value));
    }

    template <std::unsigned_integral IntegerType>
    void updateTextEntry(IntegerType value) const noexcept
    {
        panel().children()[1].clientPanel().template as<TextEntry>()
            .setText(StringBuilderStorage<100>{}.builder().put(value).cstring());
    }

private:
    [[nodiscard]] decltype(auto) panel() const noexcept
    {
        return hookContext.template make<PanoramaUiPanel>(_panel);
    }

    HookContext& hookContext;
    cs2::CUIPanel* _panel;
};
