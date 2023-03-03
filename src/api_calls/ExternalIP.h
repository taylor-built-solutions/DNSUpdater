#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

class ExternalIP
{
public:
    std::string GetExternalIPAddress();
    std::string IPAddress() { return externalIP; }

private:
    std::string externalIP;
    json externalIPJson;
}
