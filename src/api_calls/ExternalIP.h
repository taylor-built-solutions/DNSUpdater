#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
using json = nlohmann::json;

class ExternalIP
{
public:
  std::string GetExternalIPAddress();
  std::string IPAddress() const { return externalIP; }

private:
  std::string externalIP;
  json externalIPJson;
};
