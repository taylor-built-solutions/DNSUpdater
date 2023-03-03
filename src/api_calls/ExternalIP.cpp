#include "ExternalIP.h"

std::string ExternalIP::GetExternalIPAddress()
{
    cpr::Response response = cpr::Get(cpr::Url{"https://api.ipify.org?format=json"});

    externalIPJson = json::parse(response.text);
    externalIP = externalIPJson["ip"];

    fmt::print("Current External IP Address = {}\n", externalIP);

    // This should be in JSON so we'll need to parse it but return it to allow it to compile.
    return externalIP;
}

