#include "../api_calls/request_data/CloudFlareDNSUpdateData.h"
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
using json = nlohmann::json;

class SiteConfiguration
{
public:
  // Both the variable and the pointer are const.
  static const char *const skDefaultFileName;

  SiteConfiguration();// Default constructor. Assume use of default file name
  explicit SiteConfiguration(std::string filename);

  // We need some kind of parse() routine

private:
  std::string mFileName;
  bool mParsed;

  CloudFlareDNSUpdateData mDnsData;
};