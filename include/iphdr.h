#ifndef IPHDR_H
#define IPHDR_H

#include <stdint.h>

struct iphdr{

#if __BYTE_ORDER == __LITTLE_ENDIAN
  unsigned int ihl:               4;
  unsigned int version:           4;
#elif __BYTE_ORDER == __BIG_ENDIAN
  unsigned int version:           4;
  unsigned int ihl:               4;
#else
  #error "Please fix <bits/endian.h>"
#endif
  uint8_t tos;
  uint16_t tot_len;
  uint16_t id;
  uint16_t frag_off;
  uint8_t ttl;
  uint8_t protocol;
  uint16_t check;
  uint32_t saddr;
  uint32_t daddr;
};

#endif /* IPHDR_H */