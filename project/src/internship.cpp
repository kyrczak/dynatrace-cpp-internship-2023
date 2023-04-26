#include <chrono>
#include <fstream>
#include <iostream>

#include <date/date.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <nlohmann/json.hpp>

#include "internship.h"

using json = nlohmann::json;

namespace internship {
    // remove this function before submitting your solution
    void extractOS(const std::string& jsonFileName, int elementsCount, boost::gregorian::days lastBiggestValue) {
        if(elementsCount == 0) return;

        std::ifstream f(jsonFileName);
        json data = json::parse(f);
        int remainingElements = elementsCount;
        std::string OSname, OSversion;
        boost::gregorian::date releaseDate;
        boost::gregorian::date eolDate;
        boost::gregorian::days versionLife(0);
        boost::gregorian::days biggestDifference(0);

        for(const auto& [id,product] : data.items()) {
            if(product["os"] == true && remainingElements > 0) {
                for (const auto& [id, version] : product["versions"].items()) {
                    releaseDate = boost::gregorian::date(boost::gregorian::from_string(version["releaseDate"]));
                    eolDate = boost::gregorian::date(boost::gregorian::from_string(version["eol"]));
                    versionLife = eolDate - releaseDate;

                    if(versionLife > biggestDifference && versionLife < lastBiggestValue) {
                        biggestDifference = versionLife;
                        OSname = product["name"];
                        OSversion = version["cycle"];
                    }
                }
            }
        }
        elementsCount--;
        std::cout<<OSname<<" "<<OSversion<<" "<<biggestDifference.days()<<std::endl;
        extractOS(jsonFileName,elementsCount,biggestDifference);

    }
    // do not remove this function
    void solution(const std::string& jsonFileName, int elementsCount) {
        extractOS(jsonFileName,elementsCount,boost::gregorian::days(boost::gregorian::pos_infin));
    }
}