#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
using json = nlohmann::json;

class currentIP
{
public:
  // Both the variable and the pointer are const.
  static const char *const skDefaultFileName;

  currentIP();// Default constructor. Assume use of default file name
  explicit currentIP(std::string filename);

  std::string GetCurrentIP() const;
  std::string GetFileName() const { return mFileName; }
  bool UpdateCurrentIP(const std::string &externalIP);

private:
  std::string mFileName;
  std::string mCurrentIP;
  bool mParsed;
};