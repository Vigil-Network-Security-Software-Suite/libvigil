#include "../include/vigil.h"
#include <string.h>
#include <stdlib.h>
#define QUIET 1
#define PRINT 2
struct rule_data * quiet_decode(const unsigned char * restrict packet, const int packet_len){
  return full_decode(packet, packet_len, QUIET);
}
struct rule_data * print_decode(const unsigned char * restrict packet, const int packet_len){
  return full_decode(packet, packet_len, PRINT);
}
struct rule_data * full_decode(const unsigned char * packet, const int packet_len, int type){
  struct rule_data * rdata = (struct rule_data *)malloc(sizeof(struct rule_data));

  

 return rdata;
}

void free_rdata(struct rule_data * rdata){
  free(rdata);
}