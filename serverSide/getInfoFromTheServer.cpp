#include <cstdint>
#include <iostream>
#include <string>
#include <cmath>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>


void askForInfo(){
    const std::string url("http://127.0.0.1:5000/api/v1/newInfo");

    CURL* curl = curl_easy_init();

    // Set remote URL.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Don't bother trying IPv6, which would increase DNS resolution time.
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

    // Don't wait forever, time out after 10 seconds.
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

    // Follow HTTP redirects if necessary.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Response information.
    long httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

    // Hook up data container (will be passed as the last parameter to the
    // callback handling function).  Can be any pointer type, since it will
    // internally be passed as a void pointer.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (httpCode == 200)
    {
        std::cout << "\nGot successful response from " << url << std::endl;

        // Response looks good - done using Curl now.  Try to parse the results
        // and print them out.
        Json::Value jsonData;
        Json::Reader jsonReader;

        if (jsonReader.parse(*httpData.get(), jsonData))
        {
            // std::cout << "Successfully parsed JSON data" << std::endl;
            // std::cout << "\nJSON data received:" << std::endl;
            // std::cout << jsonData << std::endl;

            const std::string time(jsonData[0]["time"].asString());
            const std::string datetime(jsonData[0]["datetime"].asString());
            const std::string initialCo2In(jsonData[0]["initialCo2In"].asString());
            const std::string initialCo2Out(jsonData[0]["initialCo2Out"].asString());
            const std::string initialInTemp(jsonData[0]["initialInTemp"].asString());
            const std::string initialOutTemp(jsonData[0]["initialOutTemp"].asString());
            const std::string initialSunShineIn(jsonData[0]["initialSunShineIn"].asString());
            const std::string initialSunShineOut(jsonData[0]["initialSunShineOut"].asString());
            const std::string nextWaterTime(jsonData[0]["nextWaterTime"].asString());

            std::cout << "Sensers reads:" << std::endl;
            std::cout << "\t time: " << time << std::endl;
            std::cout << "\t co2IIn: " << initialCo2In << std::endl;
            std::cout << "\t co2Out: " << initialCo2Out << std::endl;
            std::cout << "\t inTemp: " << initialInTemp << std::endl;
            std::cout << "\t outTemp: " << initialOutTemp << std::endl;
            std::cout << "\t sunShineIn: " << initialSunShineIn << std::endl;
            std::cout << "\t sunShineOut: " << initialSunShineOut << std::endl;
            std::cout << "\t nextWeaterTime: " << nextWaterTime << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Could not parse HTTP data as JSON" << std::endl;
            std::cout << "HTTP data was:\n" << *httpData.get() << std::endl;
           
        }
    }
    else
    {
        std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
       
    }

}

int main()
{
    askForInfo();
    return 0;
}
