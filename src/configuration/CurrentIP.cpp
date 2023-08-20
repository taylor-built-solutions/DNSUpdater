#include "CurrentIP.h"
#include <fstream>

const char *const CurrentIP::skDefaultFileName = "CurrentIP.json";

CurrentIP::CurrentIP() : mFileName(skDefaultFileName), mParsed(false) {}

CurrentIP::CurrentIP(std::string filename) : mFileName{ std::move(filename) }, mParsed(false) {}

std::string CurrentIP::GetCurrentIP() const
{
  std::ifstream configFile;
  configFile.open(mFileName);

  std::string currentIPAddress;

  // This may be unnecessary but it's done to be clear that we want this string to be the empty string if the file is
  // empty.
  currentIPAddress.clear();

  if (configFile) {
    json data = json::parse(configFile);
    currentIPAddress = data["ip"];
  }

  return currentIPAddress;
}

bool CurrentIP::UpdateCurrentIP(const std::string &externalIP)
{
  bool success = false;

  if (externalIP.empty()) {
    // Log an error and return false;
    spdlog::error("CurrentIP::UpdateCurrentIP() was passed an empty string. Not updating the current IP address");
    return success;
  }

  json jsonOutput;
  jsonOutput["ip"] = externalIP;

  // Open and truncate the file. We'll overwrite whatever is there with what we know is the current IP
  std::ofstream configFile;
  configFile.open(mFileName, std::ofstream::out | std::ofstream::trunc);
  configFile << jsonOutput;

  return success;
}