#ifndef ICMPv6_H
#define ICMPv6_H

#include <stdint.h>

struct icmpv6_hdr{
  uint16_t type;
  uint16_t code;
  uint16_t checksum;
  uint32_t body;
};

#endif /* ICMPv6_H */