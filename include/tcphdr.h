#ifndef TCPHDR_H
#define TCPHDR_H

#include <stdint.h>
#include <bits/endian.h>

struct tcphdr{
  uint16_t source;
  uint16_t dest;
  uint32_t seq;
  uint32_t ack_seq;

// #if __BYTE_ORDER == __LITTLE_ENDIAN
  
};


#endif /* TCPHDR_H */