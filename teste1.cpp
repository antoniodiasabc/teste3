#include <cstdio>
#include "restclient.h"

main(){
  RestClient::Response r = RestClient::get("http://172.30.4.150:8080/main.html");
  printf("\n resposta [%s] \n", r.body.c_str());
  printf("\n resposta [%d] \n", r.code);
}
