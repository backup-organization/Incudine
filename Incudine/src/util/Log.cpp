#include "Log.h"

Log* instance;

Log::Log() {
    
}

auto Log::getLogger() -> Log* {
    if(!instance) {
        instance = new Log();
    }
    return instance;
}

auto Log::getPath() -> std::string {
    auto path = std::string(getenv("APPDATA") + std::string(R"(\..\Local\Packages\Microsoft.MinecraftUWP_8wekyb3d8bbwe\RoamingState\)"));
    return path;
}

auto Log::write(const std::string& toWrite) -> Log*{

    std::stringstream ss;
    ss << getPath() << "IncudineDebug.txt";

    std::string debugFilePath = ss.str();
    std::ofstream fileStream(debugFilePath, std::ios::out|std::ios::app);
    fileStream << toWrite;
    fileStream.close();

    return this;
}
auto Log::write(uintptr_t toWrite, bool hex) -> Log*  {
    std::stringstream ss;
    if(hex) {
        ss << std::hex << toWrite;
    }
    else {
        ss << toWrite;
    }
    this->write(ss.str());
    return this;
}
auto Log::write(float toWrite) -> Log* {
    this->write(std::to_string(toWrite));
    return this;
}
auto Log::write(void* toWrite, bool hex) -> Log* {
    return this->write((uintptr_t)toWrite, hex);
}

auto Log::writeLine(const std::string& toWrite) -> Log* {
    return this->write(toWrite+"\n");
}
auto Log::writeLine() -> Log* {
    return this->writeLine("");
}