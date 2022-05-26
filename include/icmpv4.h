#ifndef ICMPv4_H
#define ICMPv4_H

#include <stdint.h>
struct icmpv4hdr{
  uint8_t type;
  uint8_t code;
  uint16_t checksum;
  uint16_t id;
  uint16_t seq;
  uint8_t timestamp[8];
  uint8_t data[128];
};



#endif /* ICMPv4_H */