#include "browsers.h"

#include <fstream>
#include <unordered_map>
#include <cstring>

#include "textutils.hpp"
#include "error.h"

/* {"search string", "belongs to"} */
static std::unordered_map<std::string, std::string> s_browsers = {
    /* Game systems: most of them are based of major browsers,
     * thus they need to go before. */
    {"Xbox One", "Game Systems"},
    {"Xbox", "Game Systems"},
    {"PlayStation", "Game Systems"},
    {"NintendoBrowser", "Game Systems"},
    {"Valve Steam", "Game Systems"},
    {"Origin", "Game Systems"},
    {"Raptr", "Game Systems"},

    /* Based on Internet Explorer */
    {"Avant Browser", "Others"},
    /* Internet Explorer */
    {"IEMobile", "MSIE"},
    {"MSIE", "MSIE"},
    /* IE11 */
    {"Trident/7.0", "MSIE"},
    /* Microsoft Edge */
    {"Edg", "Edge"},
    {"Edge", "Edge"},

    /* Surf Browser */
    {"Surf", "Surf"},

    /* Opera */
    {"Opera Mini", "Opera"},
    {"Opera Mobi", "Opera"},
    {"Opera", "Opera"},
    {"OPR", "Opera"},
    {"OPiOS", "Opera"},
    {"Coast", "Opera"},

    /* Others */
    {"Homebrew", "Others"},
    {"APT-", "Others"},
    {"Apt-Cacher", "Others"},
    {"Aptly", "Others"},
    {"Chef Client", "Others"},
    {"Huawei", "Others"},
    {"HUAWEI", "Others"},
    {"BlackBerry", "Others"},
    {"BrowserX", "Others"},
    {"Dalvik", "Others"},
    {"Dillo", "Others"},
    {"ELinks", "Others"},
    {"Epiphany", "Others"},
    {"Firebird", "Others"},
    {"Galeon", "Others"},
    {"google-cloud-sdk", "Others"},
    {"IBrowse", "Others"},
    {"K-Meleon", "Others"},
    {"Konqueror", "Others"},
    {"Links", "Others"},
    {"Lynx", "Others"},
    {"Midori", "Others"},
    {"Minefield", "Others"},
    {"Mosaic", "Others"},
    {"Netscape", "Others"},
    {"SeaMonkey", "Others"},
    {"UCBrowser", "Others"},
    {"Wget", "Others"},
    {"libfetch", "Others"},
    {"check_http", "Others"},
    {"Go-http-client", "Others"},
    {"curl", "Others"},
    {"midori", "Others"},
    {"w3m", "Others"},
    {"MicroMessenger", "Others"},
    {"Apache", "Others"},
    {"JOSM", "Others"},
    {"pacman", "Others"},
    {"Pamac", "Others"},
    {"libwww-perl", "Others"},
    {"python-requests", "Others"},
    {"PackageKit", "Others"},
    {"F-Droid", "Others"},
    {"okhttp", "Others"},
    {"node", "Others"},
    {"PrivacyBrowser", "Others"},
    {"Transmission", "Others"},
    {"libmpv", "Others"},
    {"aria2", "Others"},

    /* Feed-reader-as-a-service */
    {"AppleNewsBot", "Feeds"},
    {"Bloglines", "Feeds"},
    {"Digg Feed Fetcher", "Feeds"},
    {"Feedbin", "Feeds"},
    {"FeedHQ", "Feeds"},
    {"Feedly", "Feeds"},
    {"Flipboard", "Feeds"},
    {"inoreader.com", "Feeds"},
    {"Netvibes", "Feeds"},
    {"NewsBlur", "Feeds"},
    {"PinRSS", "Feeds"},
    {"theoldreader.com", "Feeds"},
    {"WordPress.com Reader", "Feeds"},
    {"YandexBlogs", "Feeds"},
    {"Brainstorm", "Feeds"},
    {"Mastodon", "Feeds"},
    {"Pleroma", "Feeds"},

    /* Google crawlers (some based on Chrome,
     * therefore up on the list) */
    {"AdsBot-Google", "Crawlers"},
    {"AppEngine-Google", "Crawlers"},
    {"Mediapartners-Google", "Crawlers"},
    {"Google", "Crawlers"},
    {"WhatsApp", "Crawlers"},

    /* Based on Firefox */
    {"Camino", "Others"},
    /* Rebranded Firefox but is really unmodified
     * Firefox (Debian trademark policy) */
    {"Iceweasel", "Firefox"},
    {"Waterfox", "Firefox"},
    {"PaleMoon", "Firefox"},
    {"Focus", "Firefox"},
    /* Klar is the name of Firefox Focus in the German market. */
    {"Klar", "Firefox"},
    {"Firefox", "Firefox"},

    /* Based on Chromium */
    {"BeakerBrowser", "Beaker"},
    {"Brave", "Brave"},
    {"Vivaldi", "Vivaldi"},
    {"YaBrowser", "Yandex.Browser"},

    /* Chrome has to go before Safari */
    {"HeadlessChrome", "Chrome"},
    {"Chrome", "Chrome"},
    {"CriOS", "Chrome"},

    /* Crawlers/Bots (Possible Safari based) */
    {"AppleBot", "Crawlers"},
    {"facebookexternalhit", "Crawlers"},
    {"Twitter", "Crawlers"},

    {"Safari", "Safari"},

    /* Crawlers/Bots */
    {"Slack", "Crawlers"},
    {"Sogou", "Crawlers"},
    {"Java", "Crawlers"},
    {"Jakarta Commons-HttpClient", "Crawlers"},
    {"netEstate", "Crawlers"},
    {"PiplBot", "Crawlers"},
    {"IstellaBot", "Crawlers"},
    {"heritrix", "Crawlers"},
    {"PagesInventory", "Crawlers"},
    {"rogerbot", "Crawlers"},
    {"fastbot", "Crawlers"},
    {"yacybot", "Crawlers"},
    {"PycURL", "Crawlers"},
    {"PHP", "Crawlers"},
    {"AndroidDownloadManager", "Crawlers"},
    {"Embedly", "Crawlers"},
    {"ruby", "Crawlers"},
    {"Ruby", "Crawlers"},
    {"python", "Crawlers"},
    {"Python", "Crawlers"},
    {"LinkedIn", "Crawlers"},
    {"Microsoft-WebDAV", "Crawlers"},
    {"DuckDuckGo-Favicons-Bot", "Crawlers"},
    {"bingbot", "Crawlers"},
    {"PetalBot", "Crawlers"},
    {"Discordbot", "Crawlers"},
    {"ZoominfoBot", "Crawlers"},
    {"Googlebot", "Crawlers"},
    {"DotBot", "Crawlers"},
    {"AhrefsBot", "Crawlers"},
    {"SemrushBot", "Crawlers"},
    {"Adsbot", "Crawlers"},
    {"BLEXBot", "Crawlers"},
    {"NetcraftSurveyAgent", "Crawlers"},
    {"Netcraft Web Server Survey", "Crawlers"},
    {"masscan", "Crawlers"},
    {"MJ12bot", "Crawlers"},
    {"Pandalytics", "Crawlers"},
    {"YandexBot", "Crawlers"},
    {"Nimbostratus-Bot", "Crawlers"},
    {"HTTP Banner Detection", "Crawlers"},
    {"Hakai", "Crawlers"},
    {"WinHttp.WinHttpRequest.5", "Crawlers"},
    {"NetSystemsResearch", "Crawlers"},
    {"Nextcloud Server Crawler", "Crawlers"},
    {"CFNetwork", "Crawlers"},
    {"GoScraper", "Crawlers"},
    {"Googlebot-Image", "Crawlers"},
    {"ZmEu", "Crawlers"},
    {"DowntimeDetector", "Crawlers"},
    {"MauiBot", "Crawlers"},
    {"Cloud", "Crawlers"},
    {"stagefright", "Crawlers"},

    /* Podcast fetchers */
    {"Downcast", "Podcasts"},
    {"gPodder", "Podcasts"},
    {"Instacast", "Podcasts"},
    {"iTunes", "Podcasts"},
    {"Miro", "Podcasts"},
    {"Pocket Casts", "Podcasts"},
    {"BashPodder", "Podcasts"},

    /* Feed reader clients */
    {"Akregator", "Feeds"},
    {"Apple-PubSub", "Feeds"},
    {"BTWebClient", "Feeds"},
    {"com.apple.Safari.WebFeedParser", "Feeds"},
    {"FeedDemon", "Feeds"},
    {"Feedy", "Feeds"},
    {"Fever", "Feeds"},
    {"FreshRSS", "Feeds"},
    {"Liferea", "Feeds"},
    {"NetNewsWire", "Feeds"},
    {"RSSOwl", "Feeds"},
    {"Tiny Tiny RSS", "Feeds"},
    {"Thunderbird", "Feeds"},
    {"Winds", "Feeds"},

    {"Pingdom.com", "Uptime"},
    {"jetmon", "Uptime"},
    {"NodeUptime", "Uptime"},
    {"NewRelicPinger", "Uptime"},
    {"StatusCake", "Uptime"},
    {"internetVista", "Uptime"},
    {"Server Density Service Monitoring v2", "Uptime"},

    {"Mozilla", "Others"}};

namespace goapp {
bool Browsers::IsCrawler(const std::string& agent) { return GetBrowserType(agent) == "Crawlers"; }

std::optional<std::string> Browsers::GetBrowserType(const std::string& agent) {
  auto it = s_browsers.find(agent);
  if (it != s_browsers.end()) {
    return it->second;
  }
  return std::nullopt;
}

void AddBrowserLine(const std::string& line) {
  auto trimmed = text::Trim({line.c_str(), line.size()});
  if (line.size() == 0 || line[0] == '#') {
    return;
  }
  auto idx = line.find('\t');
  if (idx == std::string_view::npos) {
    Log::Invalids("Malformed browser entry: {}", trimmed);
    return;
  }

  std::string agent(trimmed.substr(0, idx));
  std::string type(text::TrimRight(trimmed.substr(idx)));
  if (s_browsers.count(agent) != 0) {
    Log::Invalids("Duplicate browser entry: {}", agent);
  }
  s_browsers.insert_or_assign(agent, type);
}

void Browsers::LoadBrowsersFile(const std::string& browsers_file) {
  std::ifstream file(browsers_file);
  if (file.failbit) {
    FATAL("Unable to open browsers file {}: {}", browsers_file, ::strerror(errno));
  }
  std::string str;
  while (std::getline(file, str)) {
    AddBrowserLine(str);
  }
}

std::optional<std::string> Browsers::ParseUserAgent(const std::string& user_agent) {
  if (user_agent.size() == 0) {
    return std::nullopt;
  }

  std::optional<std::string> agent = ExtractCrawlerUserAgent(user_agent);
  if (agent) {
    return agent;
  }

  return std::nullopt;
}
} // namespace goapp

/* Return the Opera 15 and beyond.
 *
 * On success, the opera string and version is returned. */
static char* parse_opera(char* token) {
  char* val = (char*)xmalloc(snprintf(NULL, 0, "Opera%s", token) + 1);
  sprintf(val, "Opera%s", token);

  return val;
}

/* Given the original user agent string, and a partial crawler match, iterate
 * back until the next delimiter is found and return occurrence.
 *
 * On error when attempting to extract crawler, NULL is returned.
 * If a possible crawler string is matched, then possible bot is returned . */
static char* parse_crawler(char* str, char* match, char* type) {
  char* ptr = NULL;
  int found = 0;

  while (match != str) {
    match--;
    if (*match == ' ' || *match == '+' || match == str) {
      found = 1;
      break;
    }
  }

  /* same addr */
  if (!found && match == str)
    return NULL;

  /* account for the previous +|space */
  if (found && match != str)
    match++;

  if ((ptr = strpbrk(match, "; ")))
    *ptr = '\0';
  /* empty string after parsing it */
  if (*match == '\0')
    return NULL;

  xstrncpy(type, "Crawlers", BROWSER_TYPE_LEN);

  return xstrdup(match);
}

/* If the following string matches are found within user agent, then it's
 * highly likely it's a possible crawler.
 * Note that this could certainly return false positives.
 *
 * If no occurrences are found, NULL is returned.
 * If an occurrence is found, a pointer to the match is returned . */
static char* check_http_crawler(char* str) {
  char* match = NULL;

  /* e.g., compatible; bingbot/2.0; +http://www.bing.com/bingbot.htm */
  if ((match = strstr(str, "; +http")))
    return match;
  /* compatible; UptimeRobot/2.0; http://www.uptimerobot.com/ */
  if ((match = strstr(str, "; http")))
    return match;
  /* Slack-ImgProxy (+https://api.slack.com/robots) */
  if ((match = strstr(str, " (+http")))
    return match;
  /*  TurnitinBot/3.0 (http://www.turnitin.com/robot/crawlerinfo.html) */
  if ((match = strstr(str, " (http")))
    return match;
  /* w3c e.g., (compatible;+Googlebot/2.1;++http://www.google.com/bot.html) */
  if ((match = strstr(str, ";++http")))
    return match;
  return NULL;
}

/* Parse the given user agent match and extract the browser string.
 *
 * If no match, the original match is returned.
 * Otherwise the parsed browser is returned. */
static char* parse_browser(char* match, char* type, int i, char*** hash) {
  char *b = NULL, *ptr = NULL, *slh = NULL;
  size_t cnt = 0, space = 0;

  match = char_replace(match, '+', '-');
  /* Check if there are spaces in the token string, that way strpbrk
   * does not stop at the first space within the token string */
  if ((cnt = count_matches(hash[i][0], ' ')) && (b = match)) {
    while (space++ < cnt && (b = strchr(b, ' ')))
      b++;
  } else
    b = match;

  xstrncpy(type, hash[i][1], BROWSER_TYPE_LEN);
  /* Internet Explorer 11 */
  if (strstr(match, "rv:11") && strstr(match, "Trident/7.0")) {
    return alloc_string("MSIE/11.0");
  }
  /* Opera +15 uses OPR/# */
  if (strstr(match, "OPR") != NULL && (slh = strrchr(match, '/'))) {
    return parse_opera(slh);
  }
  /* Opera has the version number at the end */
  if (strstr(match, "Opera") && (slh = strrchr(match, '/')) && match < slh) {
    memmove(match + 5, slh, strlen(slh) + 1);
  }
  /* IE Old */
  if (strstr(match, "MSIE") != NULL) {
    if ((ptr = strpbrk(match, ";)-")) != NULL)
      *ptr = '\0';
    match = char_replace(match, ' ', '/');
  }
  /* all others */
  else if ((ptr = strpbrk(b ? b : match, ";) ")) != NULL) {
    *ptr = '\0';
  }

  return alloc_string(match);
}

/* Given a user agent, determine the browser used.
 *
 * ###NOTE: The size of the list is proportional to the run time,
 * which makes this pretty slow
 *
 * On error, NULL is returned.
 * On success, a malloc'd  string containing the browser is returned. */
char* verify_browser(char* str, char* type) {
  char *match = NULL, *token = NULL;
  int i = 0;
  size_t j = 0;

  if (str == NULL || *str == '\0')
    return NULL;

  if ((match = check_http_crawler(str)) && (token = parse_crawler(str, match, type)))
    return token;

  /* check user's list */
  for (i = 0; i < conf.browsers_hash_idx; ++i) {
    if ((match = strstr(str, conf.user_browsers_hash[i][0])) == NULL)
      continue;
    return parse_browser(match, type, i, conf.user_browsers_hash);
  }

  /* fallback to default browser list */
  for (j = 0; j < ARRAY_SIZE(browsers); ++j) {
    if ((match = strstr(str, browsers_hash[j][0])) == NULL)
      continue;
    return parse_browser(match, type, j, browsers_hash);
  }

  if (conf.unknowns_log)
    Log::Unknowns("{:<7}{}", "[BR]", str);

  xstrncpy(type, "Unknown", BROWSER_TYPE_LEN);

  return alloc_string("Unknown");
}
