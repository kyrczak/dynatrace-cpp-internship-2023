#include <chrono>
#include <fstream>
#include <iostream>

#include <date/date.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <nlohmann/json.hpp>

#include "internship.h"

using json = nlohmann::json;
using namespace date;
using namespace boost::gregorian;

namespace internship {
    // remove this function before submitting your solution
    void example(const std::string& jsonFileName) {
        std::ifstream f(jsonFileName);
        json data = json::parse(f);

        std::cout << "Dynatrace Gdansk Summer Internship 2023\n"
                    << "UTC time now: " << std::chrono::system_clock::now() << "\n\n";

        for(const auto& [id, product] : data.items()) {
            std::cout << "Product name: " << product["name"] << "\n";
        }
    }

    void extractOS(const std::string& jsonFileName, int elementsCount) {
        std::ifstream f(jsonFileName);
        json data = json::parse(f);
        int remainingElements = elementsCount;
        date releaseDate;
        date eolDate;
        days versionLife(0);
        days lastBestVerison(0);

        for(const auto& [id,product] : data.items() {
            if(product["os"] == true && remainingElements > 0) {
                for (const auto& [id, version] : product["versions"].items()) {
                    releaseDate = date(from_string(version["releaseDate"]));
                    eolDate = date(from_string(version["eol"]));
                    versionLife = eolDate - releaseDate;
                    if(versionLife > lastBestVerison) {
                        lastBestVerison = versionLife;
                    }
                }
            }
        })
    }
    // do not remove this function
    void solution(const std::string& jsonFileName, int elementsCount) {
        example(jsonFileName); // remove this call before submitting your solution

        // put the call to your solution here
    }
}