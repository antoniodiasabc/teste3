
#include <stdio.h>
#include <string>
#include <curl/curl.h>
 
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string getXMLFile(std::string webservice, std::string msg)
{
  CURL *curl;
  CURLcode res;

  std::string readBuffer;
 
  curl_global_init(CURL_GLOBAL_ALL);
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, webservice.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, msg.c_str());

 curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
 curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

 struct curl_slist *chunk = NULL;
 
    chunk = curl_slist_append(chunk, "Accept:*/*");
 
    /* Add a custom header */ 
//    chunk = curl_slist_append(chunk, "Authorization: Bearer eyJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJhZG0iLCJhdXRoIjpbXX0.MuKsMplmjP85_AUJKNx2KasexOUoTho5BaBYs8tSctM");
 
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    printf("\n retorno [%s] \n", readBuffer.c_str());
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();

  return readBuffer;
}

int main(){
   std::string result = getXMLFile("http://localhost:8055/convert2iwxxm", "local=SBBR&msg=METAR SBSP 031900Z 17011KT 5000 BR BKN008 OVC012 19/17 Q1018=METAR SBSP 031900Z 17011KT 5000 BR BKN008 OVC012 19/17 Q1018&latitude=1&longitude=2");
   printf("\n resultado [%s] \n", result.c_str());
}
