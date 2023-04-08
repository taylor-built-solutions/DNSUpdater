#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
using json = nlohmann::json;

class currentIP
{
public:
  currentIP();// Default constructor. Assume use of default file name
  explicit currentIP(std::string filename);

  std::string GetCurrentIP();
  bool UpdateCurrentIP(const std::string &externalIP);

private:
  std::string mFileName;
  std::string mCurrentIP;
  bool mParsed;
};