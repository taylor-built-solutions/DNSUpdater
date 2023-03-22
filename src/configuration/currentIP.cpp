#include "currentIP.h"
#include <fstream>

const std::string currentIP::skDefaultFileName = "currentIP.json";

currentIP::currentIP() : mParsed = false { mFilenName = skDefaultFileName; }

currentIP::currentIP(std::string filename) : mFileName = filename, mParsed = false {}

std::string currentIP::GetCurrentIP()
{
  ifstream configFile;
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

bool currentIP::UpdateCurrentIP(std::string externalIP)
{
  bool success = false;

  if (externalIP.empty()) {
    // Log an error and return false;
    spdlog::error("currentIP::UpdateCurrentIP() was passed an empty string. Not updating the current IP address");
    return success;
  }

  json jsonOutput;
  jsonOutput["ip"] = externalIP;

  // Open and truncate the file. We'll overwrite whatever is there with what we know is the current IP
  ofstream configFile;
  configFile.open(mFileName, std::ofstream::out | std::ofsteram::trunc);
  configFile << jsonOutput;

  return success;
}