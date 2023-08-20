#include "SiteConfiguration.h"

const char *const SiteConfiguration::skDefaultFileName = "SiteConfiguration.json";

SiteConfiguration::SiteConfiguration() : mFileName(skDefaultFileName), mParsed(false) {}

SiteConfiguration::SiteConfiguration(std::string filename) : mFileName{ std::move(filename) }, mParsed(false) {}