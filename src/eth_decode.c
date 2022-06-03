#include <vigil/vigil.h>
#include <vigil/if_ether.h>
#include <stdio.h>

void eth_decode(struct rule_data * rdata){
  struct ethhdr * ethernet_header = (struct ethhdr *)rdata->full_packet;
  printf("%s -> %s\n",mac_ntoa(ethernet_header->h_source),mac_ntoa(ethernet_header->h_dest));


}