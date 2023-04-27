#include <string>

class CloudFlareDNSUpdateData
{
public:
  // Request Data Names
  static const char *const skContent;
  static const char *const skName;
  static const char *const skProxied;
  static const char *const skType;
  static const char *const skComment;
  static const char *const skTags;

  // Data members
  std::string content;// IP Address for DNS updates
  std::string name;// Domain name for DNS updates
  std::string proxied;// Whether the DNS record is proxied
  std::string type;// DNS record type
  std::string comment;
  std::string tags;
};