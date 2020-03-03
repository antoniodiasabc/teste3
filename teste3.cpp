#include <cstdio>
#include "restclient.h"

main(){
  RestClient::Response r = RestClient::get("http://10.103.3.46:8044/actuator/health");
  printf("\n resposta [%s] \n", r.body.c_str());
  printf("\n resposta [%d] \n", r.code);
}
