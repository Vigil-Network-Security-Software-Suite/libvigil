#include "../include/vigil.h"
#include <string.h>
#include <stdlib.h>
struct rule_data * full_decode(const unsigned char * packet, const int packet_len){
  struct rule_data * rdata = (struct rule_data *)malloc(sizeof(struct rule_data));
  rdata->pkt = packet; 
  rdata->full_packet = packet; 
  eth_decode(rdata);
  return rdata;
}

void free_rdata(struct rule_data * rdata){
  free(rdata);
}