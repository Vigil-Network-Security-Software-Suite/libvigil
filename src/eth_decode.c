#include <vigil/vigil.h>
#include <vigil/if_ether.h>

void eth_decode(struct rule_data * rdata){
  struct ethhdr * ethernet_header = (struct ethhdr *)rdata->full_packet;
  
}