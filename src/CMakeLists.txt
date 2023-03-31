find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Generic test that uses conan libs
add_executable(DNSUpdater main.cpp api_calls/ExternalIP.cpp)
target_link_libraries(
  DNSUpdater
  PUBLIC project_options project_warnings
  PRIVATE CLI11::CLI11 fmt::fmt spdlog::spdlog cpr::cpr nlohmann_json::nlohmann_json)

target_include_directories(DNSUpdater PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")
