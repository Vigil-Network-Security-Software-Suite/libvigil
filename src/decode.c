#include "../include/vigil.h"
#include <string.h>
#include <stdlib.h>s
struct rule_data * full_decode(const unsigned char * packet, const int packet_len){
  struct rule_data * rdata = (struct rule_data *)malloc(sizeof(struct rule_data));

  

 return rdata;
}

void free_rdata(struct rule_data * rdata){
  free(rdata);
}