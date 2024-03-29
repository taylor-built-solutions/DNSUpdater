#include "currentIP.h"
#include <catch2/catch_test_macros.hpp>
#include <fstream>

TEST_CASE("currentIP_UpdateCurrentIP_Test", "[currentIP]")
{
  currentIP initialIP;
  std::remove(currentIP::skDefaultFileName);

  SECTION("Default File Name, No previously existing file")
  {
    std::string ipAddress = initialIP.GetCurrentIP();
    std::string fileName = initialIP.GetFileName();

    REQUIRE(ipAddress.empty());
    REQUIRE(fileName == currentIP::skDefaultFileName);
  }

  SECTION("Default File Name, No previously existing file, Update the IP Address")
  {
    initialIP.UpdateCurrentIP("1.1.1.1");

    std::string ipAddress = initialIP.GetCurrentIP();
    std::string fileName = initialIP.GetFileName();

    std::ifstream fileStream;
    fileStream.open(fileName.c_str(), std::fstream::in);

    REQUIRE(ipAddress == "1.1.1.1");
    REQUIRE(fileName == currentIP::skDefaultFileName);
    REQUIRE(fileStream.is_open());
  }
}