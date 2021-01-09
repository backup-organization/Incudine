#include <iostream>
#include <filesystem>
#include "loadlib.h"
#include "process.h"
#include "escalation.h"

auto main() -> int {
    const auto proc = process::getPID("Minecraft.Windows.exe");
    const auto image = std::filesystem::current_path().string() + "\\Ignite.dll";
    escalation::elevate(image);
    loadlib::inject(image, proc);
    return 0;
}