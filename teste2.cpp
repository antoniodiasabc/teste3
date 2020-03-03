#include <cstdio>
#include "restclient.h"
#include "connection.h"

main(){

// initialize RestClient
 RestClient::init();
//
// // get a connection object
 RestClient::Connection* conn = new RestClient::Connection("https://localhost:8453/");
//
// // configure basic auth
// conn->SetBasicAuth("WarMachine68", "WARMACHINEROX");
//
// // set connection timeout to 5s
 //conn->SetTimeout(5);
//
// // set custom user agent
// // (this will result in the UA "foo/cool restclient-cpp/VERSION")
// conn->SetUserAgent("foo/cool");
//
// // enable following of redirects (default is off)
// conn->FollowRedirects(true);
// // and limit the number of redirects (default is -1, unlimited)
// conn->FollowRedirects(true, 3);
//
// // set headers
 RestClient::HeaderFields headers;
 headers["Accept"] ="*/*";

 conn->SetHeaders(headers);

// // append additional headers
 conn->AppendHeader("Authorization", "Bearer eyJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJhZG0iLCJhdXRoIjpbXX0.MuKsMplmjP85_AUJKNx2KasexOUoTho5BaBYs8tSctM");
//
// // if using a non-standard Certificate Authority (CA) trust file
// conn->SetCAInfoFilePath("/etc/custom-ca.crt")
//
  RestClient::Response r = conn->get("searchiwxxm?local=SBBR&msg=TAF&data_ini=2020030200&data_fim=2020030220");
  printf("\n resposta [%s] \n", r.body.c_str());
  printf("\n resposta [%d] \n", r.code);

// RestClient::Response r = conn->head("/get")
// RestClient::Response r = conn->del("/delete")
// RestClient::Response r = conn->options("/options")
//
// // set different content header for POST, PUT and PATCH
 conn->AppendHeader("Content-Type", "application/json");
  r = conn->post("searchiwxxm", "local=SBBR&msg=TAF&data_ini=2020030200&data_fim=2020030220");
  printf("\n resposta [%s] \n", r.body.c_str());
  printf("\n resposta [%d] \n", r.code);
//
///
// RestClient::Response r = conn->put("/put", "application/json", "{\"foo\": \"bla\"}")
// RestClient::Response r = conn->patch("/patch", "text/plain", "foobar")
//
// // deinit RestClient. After calling this you have to call RestClient::init()
// // again before you can use it

 RestClient::disable();

}
