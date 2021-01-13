#ifndef INCUDINE_VERSIONUTILS_H
#define INCUDINE_VERSIONUTILS_H

#include <Windows.h>
#include "Log.h"

enum SupportedVersion {
    MC_1_16_201_2,
    MC_1_12_1_1,
    MC_UNSUPPORTED
};

class VersionUtils {
    static inline SupportedVersion theVersion;
public:
    static auto calculateVersion() -> SupportedVersion;
    static auto getVersion() -> SupportedVersion;
    static auto strToVer(std::string) -> SupportedVersion;
    static auto verToStr(SupportedVersion) -> std::string;
};

#endif /* INCUDINE_VERSIONUTILS_H */
