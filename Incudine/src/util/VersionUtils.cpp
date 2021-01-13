#include "VersionUtils.h"

#define LMC_EXE L"Minecraft.Windows.exe"
#define MC_EXE "Minecraft.Windows.exe"

auto VersionUtils::strToVer(std::string str) -> SupportedVersion {

    if(str == "1.16.201.2") {
        return MC_1_16_201_2;
    }
    if(str == "1.12.1.1") {
        return MC_1_12_1_1;
    }

    return MC_UNSUPPORTED;
}
auto VersionUtils::verToStr(SupportedVersion ver) -> std::string {
    switch(ver) {
    case MC_1_16_201_2:
        return "1.16.201.2";
    case MC_1_12_1_1:
        return "1.12.1.1";
    default:
        return "Unsupported";
    }
}


auto VersionUtils::getVersion() -> SupportedVersion {
    if(!theVersion)
        theVersion = calculateVersion();
    return theVersion;
}

auto VersionUtils::calculateVersion() -> SupportedVersion {
    DWORD  verHandle = 0;
    UINT   size      = 0;
    LPBYTE lpBuffer  = NULL;
    DWORD  verSize   = GetFileVersionInfoSizeA( MC_EXE, &verHandle);

    if (verSize != NULL)
    {
        LPSTR verData = new char[verSize];

        if (GetFileVersionInfoA( MC_EXE, verHandle, verSize, verData))
        {
            if (VerQueryValue(verData, TEXT("\\"), (VOID FAR* FAR*)&lpBuffer, &size))
            {
                if (size)
                {
                    VS_FIXEDFILEINFO *verInfo = (VS_FIXEDFILEINFO *)lpBuffer;
                    if (verInfo->dwSignature == 0xfeef04bd)
                    {

                        // Doesn't matter if you are on 32 bit or 64 bit,
                        // DWORD is always 32 bits, so first two revision numbers
                        // come from dwFileVersionMS, last two come from dwFileVersionLS
                        int verMS_Top = ( verInfo->dwFileVersionMS >> 16 ) & 0xffff;
                        int verMS_Bottom = ( verInfo->dwFileVersionMS >> 0 ) & 0xffff;
                        int verLS_Top = ( verInfo->dwFileVersionLS >> 16 ) & 0xffff;
                        int verLS_Bottom = ( verInfo->dwFileVersionLS >> 0 ) & 0xffff;


                        std::stringstream ss;
                        ss << verMS_Top << "." << verMS_Bottom << "." << verLS_Top << "." << verLS_Bottom;
                        std::string version = ss.str();

                        Log::getLogger()->write("Got MC Version: ")->writeLine(version);

                        delete[] verData;

                        return strToVer(version);
                    }
                }
            }
        }
        delete[] verData;
    }
    return MC_UNSUPPORTED;
};