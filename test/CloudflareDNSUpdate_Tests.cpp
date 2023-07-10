#include "CloudflareDNSUpdate.h"
#include <catch2/catch_test_macros.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

TEST_CASE("GetDNSRecords_Tests")
{
  SECTION("Correct Zone and API Token")
  {
    std::string zoneID = "yourvaluehere";
    std::string apiToken = "yourvaluehere";

    json response = CloudflareDNSUpdate::GetDNSRecords(zoneID, apiToken);

    REQUIRE(response != nullptr);

    json errors = nullptr;

    try {
      errors = response.at("errors");

      if (!errors.empty()) {
        std::string errorString = errors.dump();
        fmt::print("Cloudflare returned errors: {}", errorString);
      }
    } catch (const json::out_of_range &e) {
      fmt::print("Got exception of type nlohmann::basic_json::out_of_range with message {}\n", e.what());
    }

    REQUIRE(errors.empty());

    json dnsRecords;
    try {
      dnsRecords = response.at("result");

      if (!dnsRecords.empty()) {
        for (const auto &it : dnsRecords) { fmt::print("{}\n", it.dump()); }
      }
    } catch (const json::out_of_range &e) {
      fmt::print("Got exception of type nlohmann::basic_json::out_of_range with message {}\n", e.what());
    }

    REQUIRE(!dnsRecords.empty());
  }
}