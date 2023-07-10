#include "CloudflareDNSUpdate.h"

const char *const CloudflareDNSUpdate::skDnsUrl = "https://api.cloudflare.com/client/v4/zones/";
const char *const CloudflareDNSUpdate::skDnsRecordsPath = "/dns_records";

json CloudflareDNSUpdate::GetDNSRecords(const std::string &zoneID, const std::string &apiKey)
{
  std::string url = CloudflareDNSUpdate::skDnsUrl + zoneID;
  url += skDnsRecordsPath;
  cpr::Header header = { { "Content-Type", "application/json" }, { "Authorization", "Bearer " + apiKey } };

  cpr::Response response = cpr::Get(cpr::Url{ url }, header);

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

  // if the dns record ID is blank
  //    do a listing on the dns records to get it and save it to the configuration file
  //    This would be better done for all of the items in the configuration file at once.

  // Set the dns record ID to the URL


  // cpr response = cpr::Put(cpr::Url(),)
}