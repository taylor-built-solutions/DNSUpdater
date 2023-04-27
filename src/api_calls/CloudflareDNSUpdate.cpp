#include "CloudflareDNSUpdate.h"

void CloudflareDNSUpdate::UpdateDNSRecord(const CloudFlareDNSUpdateData &data)
{
  json requestBody;

  requestBody[CloudFlareDNSUpdateData::skContent] = data.content;
  requestBody[CloudFlareDNSUpdateData::skName] = data.name;
  requestBody[CloudFlareDNSUpdateData::skProxied] = data.proxied;
  requestBody[CloudFlareDNSUpdateData::skType] = data.type;
  requestBody[CloudFlareDNSUpdateData::skComment] = data.comment;
  requestBody[CloudFlareDNSUpdateData::skTags] = data.tags;
}