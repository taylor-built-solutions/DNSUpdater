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


    return success;
  }

  return success;
}