#include <vigil/vigil.h>
#include <vigil/if_ether.h>
#include <stdio.h>
#include <string.h>
void eth_decode(struct rule_data * rdata){
  struct ethhdr * ethernet_header = (struct ethhdr *)rdata->full_packet;
  unsigned char src_addr[24];
  unsigned char dest_addr[24];
  strcpy((char *)&dest_addr,(char *)mac_ntoa(ethernet_header->h_dest));
  strcpy((char *)&src_addr, (char *)mac_ntoa(ethernet_header->h_source));
  
  sprintf(rdata->packet_repr,"%s -> %s ",src_addr,dest_addr);

  switch(ethernet_header->h_proto){
    
  }
  


}