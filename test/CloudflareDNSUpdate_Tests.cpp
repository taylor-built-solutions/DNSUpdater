#include "CloudflareDNSUpdate.h"
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("GetDNSRecords_Tests")
{
  SECTION("Correct Zone and API Token")
  {
    std::string zoneID = "caa4e3c8174cd5882361dcdcf2fff532";
    std::string apiToken = "1234567893feefc5f0q5000bfo0c38d90bbeb";

    json response = CloudflareDNSUpdate::GetDNSRecords(zoneID, apiToken);

    REQUIRE(response != nullptr);
  }
}