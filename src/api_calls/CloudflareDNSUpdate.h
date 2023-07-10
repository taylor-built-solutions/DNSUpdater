#include "request_data/CloudFlareDNSUpdateData.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
using json = nlohmann::json;

class CloudflareDNSUpdate
{
public:
  static const char *const skDnsUrl;
  static const char *const skDnsRecordsPath;

  static json GetDNSRecords(const std::string &zoneID, const std::string &apiKey);
  static void UpdateDNSRecord(const CloudFlareDNSUpdateData &data);

private:
  // Put a DNS configuration option here to read the sites to update and do the configuration during construction
  // Should the configuration happen in the control class/function (e.g. main) and have them loop through updating
  // records?
};