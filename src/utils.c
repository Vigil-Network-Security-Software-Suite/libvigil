#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
static __thread unsigned char buffer[128];
// raw mac address to char array
unsigned char * mac_ntoa(const uint8_t * hw_addr){
  unsigned char * __hwaddr = (unsigned char *)hw_addr;
  sprintf((char *)buffer,"%02x:%02x:%02x:%02x:%02x:%02x",
      __hwaddr[0], __hwaddr[1], __hwaddr[2],
      __hwaddr[3], __hwaddr[4], __hwaddr[4]
  );
  return buffer;
} 

// make address bytes to char array
unsigned char * uc_mac_ntoa(unsigned char * hw_addr){
  snprintf((char *)buffer,sizeof(buffer),
            "%02x:%02x:%02x:%02x:%02x:%02x",
            hw_addr[0],hw_addr[1],hw_addr[2],
            hw_addr[3], hw_addr[4],hw_addr[6]);
  return buffer;
}

// inet_ntoa but but for raw bytes
unsigned char * ipv4_ntoa(uint32_t ipv4addr){
  unsigned char * ipaddr = (unsigned char *)&ipv4addr;
  snprintf((char *)buffer,sizeof(buffer),"%d.%d.%d.%d",
        ipaddr[0],ipaddr[1],ipaddr[2],ipaddr[3]);
  return buffer;
}

// uin8_t[6] to char array
unsigned char * u8_ipv4_ntoa(uint8_t * ipv4addr){
  unsigned char * ipaddr = (unsigned char *)ipv4_ntoa;
  snprintf((char *)buffer,sizeof(buffer),"%d.%d.%d.%d",
    ipaddr[0],ipaddr[1],ipaddr[2],ipaddr[3]);

  return buffer;
}

// ipv4_nto but for ipv6
unsigned char * inet6_ntoa(uint8_t * ipv6addr){
   unsigned char *bytes;
  memset(buffer,0,128);
  memset(&bytes, 0, sizeof(bytes));
  bytes = (unsigned char *)ipv6addr;
  snprintf((char *)buffer, sizeof(buffer),"%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x",
    ipv6addr[0],ipv6addr[1],ipv6addr[2],ipv6addr[3],
    ipv6addr[4],ipv6addr[5],ipv6addr[6], ipv6addr[7],
    ipv6addr[8], ipv6addr[9], ipv6addr[10], ipv6addr[11],
    ipv6addr[12] ,ipv6addr[13], ipv6addr[14], ipv6addr[15]
  );
  return buffer;
}

// 12:23:34:45:56 to raw integer
void hw_addr_to_bytes(const char * str, uint8_t * output){
  char * p = strtok(str,":");
  int times = 0;
  
  while(p != NULL){
    output[times++] = (uint8_t)strtol(p,NULL,16);
    p = strtok(NULL,":");
  }

}