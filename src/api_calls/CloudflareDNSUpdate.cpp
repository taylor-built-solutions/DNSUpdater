#include "CloudflareDNSUpdate.h"

const char *const skDnsUrl = "https://api.cloudflare.com/client/v4/zones/";

json GetDNSRecords(const std::string &zoneID, const std::string &apiKey)
{
  std::string url = skDnsUrl + zoneID + "/dns_records";// make "/dns_records" static?
  cpr::Response response =
    cpr::Get(cpr::Url{ url }, cpr::Header{ { "Content-Type", "application/json" }, { "X-Auth-Email", apiKey } });

  return json::parse(response.text);
}

void CloudflareDNSUpdate::UpdateDNSRecord(const CloudFlareDNSUpdateData &data)
{
  json requestBody;

  requestBody[CloudFlareDNSUpdateData::skContent] = data.content;
  requestBody[CloudFlareDNSUpdateData::skName] = data.name;
  requestBody[CloudFlareDNSUpdateData::skProxied] = data.proxied;
  requestBody[CloudFlareDNSUpdateData::skType] = data.type;
  requestBody[CloudFlareDNSUpdateData::skComment] = data.comment;
  requestBody[CloudFlareDNSUpdateData::skTags] = data.tags;

  // The zone identifier is static for a single site.
  // Given that, I am ok if this is looked up by the user by hand and put in the configuration.
  // std::string zoneID = ""
  //  :

  std::string dnsRecords = "dns_records";// Could be static but where?

  // if the dns record ID is blank
  //    do a listing on the dns records to get it and save it to the configuration file
  //    This would be better done for all of the items in the configuration file at once.

  // Set the dns record ID to the URL


  // cpr response = cpr::Put(cpr::Url(),)
}