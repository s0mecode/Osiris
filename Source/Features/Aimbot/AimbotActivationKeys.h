#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace aimbot
{

enum class ActivationInputType : std::uint8_t {
    Keyboard,
    Mouse
};

struct ActivationKeyBinding {
    ActivationInputType inputType;
    std::uint16_t code;
};

constexpr std::array<ActivationKeyBinding, 109> kActivationKeyBindings{
    ActivationKeyBinding{ActivationInputType::Keyboard, 14},  // K
    ActivationKeyBinding{ActivationInputType::Keyboard, 226}, // Left Alt
    ActivationKeyBinding{ActivationInputType::Keyboard, 225}, // Left Shift
    ActivationKeyBinding{ActivationInputType::Keyboard, 6},   // C
    ActivationKeyBinding{ActivationInputType::Keyboard, 27},  // X
    ActivationKeyBinding{ActivationInputType::Mouse, 1},      // MOUSE_0 (left)
    ActivationKeyBinding{ActivationInputType::Mouse, 2},      // MOUSE_1 (right)
    ActivationKeyBinding{ActivationInputType::Mouse, 3},      // MOUSE_2 (middle)
    ActivationKeyBinding{ActivationInputType::Mouse, 4},      // MOUSE_3 (x1)
    ActivationKeyBinding{ActivationInputType::Mouse, 5},      // MOUSE_4 (x2)
    ActivationKeyBinding{ActivationInputType::Keyboard, 41},  // Esc
    ActivationKeyBinding{ActivationInputType::Keyboard, 58},  // F1
    ActivationKeyBinding{ActivationInputType::Keyboard, 59},  // F2
    ActivationKeyBinding{ActivationInputType::Keyboard, 60},  // F3
    ActivationKeyBinding{ActivationInputType::Keyboard, 61},  // F4
    ActivationKeyBinding{ActivationInputType::Keyboard, 62},  // F5
    ActivationKeyBinding{ActivationInputType::Keyboard, 63},  // F6
    ActivationKeyBinding{ActivationInputType::Keyboard, 64},  // F7
    ActivationKeyBinding{ActivationInputType::Keyboard, 65},  // F8
    ActivationKeyBinding{ActivationInputType::Keyboard, 66},  // F9
    ActivationKeyBinding{ActivationInputType::Keyboard, 67},  // F10
    ActivationKeyBinding{ActivationInputType::Keyboard, 68},  // F11
    ActivationKeyBinding{ActivationInputType::Keyboard, 69},  // F12
    ActivationKeyBinding{ActivationInputType::Keyboard, 53},  // `
    ActivationKeyBinding{ActivationInputType::Keyboard, 30},  // 1
    ActivationKeyBinding{ActivationInputType::Keyboard, 31},  // 2
    ActivationKeyBinding{ActivationInputType::Keyboard, 32},  // 3
    ActivationKeyBinding{ActivationInputType::Keyboard, 33},  // 4
    ActivationKeyBinding{ActivationInputType::Keyboard, 34},  // 5
    ActivationKeyBinding{ActivationInputType::Keyboard, 35},  // 6
    ActivationKeyBinding{ActivationInputType::Keyboard, 36},  // 7
    ActivationKeyBinding{ActivationInputType::Keyboard, 37},  // 8
    ActivationKeyBinding{ActivationInputType::Keyboard, 38},  // 9
    ActivationKeyBinding{ActivationInputType::Keyboard, 39},  // 0
    ActivationKeyBinding{ActivationInputType::Keyboard, 45},  // -
    ActivationKeyBinding{ActivationInputType::Keyboard, 46},  // =
    ActivationKeyBinding{ActivationInputType::Keyboard, 42},  // Backspace
    ActivationKeyBinding{ActivationInputType::Keyboard, 43},  // Tab
    ActivationKeyBinding{ActivationInputType::Keyboard, 20},  // Q
    ActivationKeyBinding{ActivationInputType::Keyboard, 26},  // W
    ActivationKeyBinding{ActivationInputType::Keyboard, 8},   // E
    ActivationKeyBinding{ActivationInputType::Keyboard, 21},  // R
    ActivationKeyBinding{ActivationInputType::Keyboard, 23},  // T
    ActivationKeyBinding{ActivationInputType::Keyboard, 28},  // Y
    ActivationKeyBinding{ActivationInputType::Keyboard, 24},  // U
    ActivationKeyBinding{ActivationInputType::Keyboard, 12},  // I
    ActivationKeyBinding{ActivationInputType::Keyboard, 18},  // O
    ActivationKeyBinding{ActivationInputType::Keyboard, 19},  // P
    ActivationKeyBinding{ActivationInputType::Keyboard, 47},  // [
    ActivationKeyBinding{ActivationInputType::Keyboard, 48},  // ]
    ActivationKeyBinding{ActivationInputType::Keyboard, 49},  // Backslash
    ActivationKeyBinding{ActivationInputType::Keyboard, 57},  // Caps Lock
    ActivationKeyBinding{ActivationInputType::Keyboard, 4},   // A
    ActivationKeyBinding{ActivationInputType::Keyboard, 22},  // S
    ActivationKeyBinding{ActivationInputType::Keyboard, 7},   // D
    ActivationKeyBinding{ActivationInputType::Keyboard, 9},   // F
    ActivationKeyBinding{ActivationInputType::Keyboard, 10},  // G
    ActivationKeyBinding{ActivationInputType::Keyboard, 11},  // H
    ActivationKeyBinding{ActivationInputType::Keyboard, 13},  // J
    ActivationKeyBinding{ActivationInputType::Keyboard, 15},  // L
    ActivationKeyBinding{ActivationInputType::Keyboard, 51},  // ;
    ActivationKeyBinding{ActivationInputType::Keyboard, 52},  // '
    ActivationKeyBinding{ActivationInputType::Keyboard, 40},  // Enter
    ActivationKeyBinding{ActivationInputType::Keyboard, 224}, // Left Ctrl
    ActivationKeyBinding{ActivationInputType::Keyboard, 227}, // Left GUI
    ActivationKeyBinding{ActivationInputType::Keyboard, 44},  // Space
    ActivationKeyBinding{ActivationInputType::Keyboard, 230}, // Right Alt
    ActivationKeyBinding{ActivationInputType::Keyboard, 231}, // Right GUI
    ActivationKeyBinding{ActivationInputType::Keyboard, 101}, // Menu
    ActivationKeyBinding{ActivationInputType::Keyboard, 228}, // Right Ctrl
    ActivationKeyBinding{ActivationInputType::Keyboard, 29},  // Z
    ActivationKeyBinding{ActivationInputType::Keyboard, 25},  // V
    ActivationKeyBinding{ActivationInputType::Keyboard, 5},   // B
    ActivationKeyBinding{ActivationInputType::Keyboard, 17},  // N
    ActivationKeyBinding{ActivationInputType::Keyboard, 16},  // M
    ActivationKeyBinding{ActivationInputType::Keyboard, 54},  // ,
    ActivationKeyBinding{ActivationInputType::Keyboard, 55},  // .
    ActivationKeyBinding{ActivationInputType::Keyboard, 56},  // /
    ActivationKeyBinding{ActivationInputType::Keyboard, 229}, // Right Shift
    ActivationKeyBinding{ActivationInputType::Keyboard, 70},  // Print Screen
    ActivationKeyBinding{ActivationInputType::Keyboard, 71},  // Scroll Lock
    ActivationKeyBinding{ActivationInputType::Keyboard, 72},  // Pause
    ActivationKeyBinding{ActivationInputType::Keyboard, 73},  // Insert
    ActivationKeyBinding{ActivationInputType::Keyboard, 74},  // Home
    ActivationKeyBinding{ActivationInputType::Keyboard, 75},  // Page Up
    ActivationKeyBinding{ActivationInputType::Keyboard, 76},  // Delete
    ActivationKeyBinding{ActivationInputType::Keyboard, 77},  // End
    ActivationKeyBinding{ActivationInputType::Keyboard, 78},  // Page Down
    ActivationKeyBinding{ActivationInputType::Keyboard, 82},  // Up
    ActivationKeyBinding{ActivationInputType::Keyboard, 80},  // Left
    ActivationKeyBinding{ActivationInputType::Keyboard, 81},  // Down
    ActivationKeyBinding{ActivationInputType::Keyboard, 79},  // Right
    ActivationKeyBinding{ActivationInputType::Keyboard, 83},  // Num Lock
    ActivationKeyBinding{ActivationInputType::Keyboard, 84},  // NumPad /
    ActivationKeyBinding{ActivationInputType::Keyboard, 85},  // NumPad *
    ActivationKeyBinding{ActivationInputType::Keyboard, 86},  // NumPad -
    ActivationKeyBinding{ActivationInputType::Keyboard, 87},  // NumPad +
    ActivationKeyBinding{ActivationInputType::Keyboard, 88},  // NumPad Enter
    ActivationKeyBinding{ActivationInputType::Keyboard, 89},  // NumPad 1
    ActivationKeyBinding{ActivationInputType::Keyboard, 90},  // NumPad 2
    ActivationKeyBinding{ActivationInputType::Keyboard, 91},  // NumPad 3
    ActivationKeyBinding{ActivationInputType::Keyboard, 92},  // NumPad 4
    ActivationKeyBinding{ActivationInputType::Keyboard, 93},  // NumPad 5
    ActivationKeyBinding{ActivationInputType::Keyboard, 94},  // NumPad 6
    ActivationKeyBinding{ActivationInputType::Keyboard, 95},  // NumPad 7
    ActivationKeyBinding{ActivationInputType::Keyboard, 96},  // NumPad 8
    ActivationKeyBinding{ActivationInputType::Keyboard, 97},  // NumPad 9
    ActivationKeyBinding{ActivationInputType::Keyboard, 98},  // NumPad 0
    ActivationKeyBinding{ActivationInputType::Keyboard, 99}   // NumPad .
};

constexpr std::uint32_t mouseButtonMask(std::uint8_t button) noexcept
{
    return std::uint32_t{1} << (button - 1);
}

}
