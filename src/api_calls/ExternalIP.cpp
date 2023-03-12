#include "ExternalIP.h"

std::string ExternalIP::GetExternalIPAddress()
{
  cpr::Response response = cpr::Get(cpr::Url{ "https://api.ipify.org?format=json" });

  mExternalIPJson = json::parse(response.text);
  mExternalIP = mExternalIPJson["ip"];

  fmt::print("Current External IP Address = {}\n", mExternalIP);

  return mExternalIP;
}
