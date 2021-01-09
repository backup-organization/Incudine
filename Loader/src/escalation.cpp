#include "escalation.h"

auto escalation::elevate(const std::string& file) -> bool {
    PACL pOldDACL = nullptr;
    PACL pNewDACL = nullptr;
    PSECURITY_DESCRIPTOR pSD = nullptr;
    EXPLICIT_ACCESS eaAccess;
    SECURITY_INFORMATION siInfo = DACL_SECURITY_INFORMATION;
    DWORD dwResult = ERROR_SUCCESS;
    PSID pSID;

    dwResult = GetNamedSecurityInfo(file.c_str(), SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, nullptr, nullptr, &pOldDACL, nullptr, &pSD);
    if (dwResult != ERROR_SUCCESS) {
        if (pSD != nullptr) {
            LocalFree((HLOCAL)pSD);
            return false;
        }
    }

    ConvertStringSidToSid("S-1-15-2-1", &pSID);
    if (pSID == nullptr) {
        if (pSD != nullptr) {
            LocalFree((HLOCAL)pSD);
            return false;
        }
    }

    ZeroMemory(&eaAccess, sizeof(EXPLICIT_ACCESS));
    eaAccess.grfAccessPermissions = GENERIC_READ | GENERIC_EXECUTE;
    eaAccess.grfAccessMode = SET_ACCESS;
    eaAccess.grfInheritance = SUB_CONTAINERS_AND_OBJECTS_INHERIT;
    eaAccess.Trustee.TrusteeForm = TRUSTEE_IS_SID;
    eaAccess.Trustee.TrusteeType = TRUSTEE_IS_WELL_KNOWN_GROUP;
    eaAccess.Trustee.ptstrName = reinterpret_cast<LPCH>(pSID);

    dwResult = SetEntriesInAcl(1, &eaAccess, pOldDACL, &pNewDACL);
    if (ERROR_SUCCESS != dwResult) {
        if (pSD != nullptr) {
            LocalFree((HLOCAL)pSD);
            return false;
        }
        if (pNewDACL != nullptr) {
            LocalFree((HLOCAL)pNewDACL);
            return false;
        }
    }

    dwResult = SetNamedSecurityInfoA(const_cast<char*>(file.c_str()), SE_FILE_OBJECT, siInfo, nullptr, nullptr, pNewDACL, nullptr);
    if (ERROR_SUCCESS != dwResult) {
        if (pSD != nullptr) {
            LocalFree((HLOCAL)pSD);
            return false;
        }
        if (pNewDACL != nullptr) {
            LocalFree((HLOCAL)pNewDACL);
            return false;
        }
    }

    return true;
}