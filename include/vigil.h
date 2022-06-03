#ifndef VIGIL_H
#define VIGIL_H
#include <stdint.h>
#include <regex.h>
#include <stdbool.h>

#ifdef lib_pcap_pcap_h
  #include <pcap.h>
#endif
// variable headers
typedef struct {
  unsigned int type;
  void * header;
} var_header;


/* RULE STRUCTURES  */
// rule_data is created when a frame is decoded into a packet usually
// this contains everything needed for rulemgr
struct rule_data{
  unsigned char * pkt;                          // packet bytes
  unsigned char * full_packet;
  char * src_ip_addr;                           // pointer to src address
  char * dest_ip_addr;                          // pointer to dest address
  uint32_t srcip;                               // may delete
  uint32_t destip;                              // may delete
  int flow;                                     // direction of traffic
  unsigned int src_port;                        // source port
  unsigned int dest_port;                       // destination port
  int __protocol;                               // protocol, see R_ICMP, R_UDP, etc
  int pkt_len;                                  // length of entire packet
  unsigned int dsize;                           // size of packet data(e.g. size of http request)
  var_header datalink_header;
  var_header network_header;
  var_header transport_header;
  var_header application_data;
  char packet_repr[256];
  unsigned char tcp_flags[8];                   // TCP flags in single character for such as
                                                //  "S" for SYN and "A" for ACK
  int is_established;                           // whether or not the tcp session is established
  
};
// Traffic flows
#define FLOW_OUTWARD                            69
#define FLOW_INWARD                             70
#define FLOW_EITHER                             71

struct rule_data * full_decode(const unsigned char * restrict packet, const int packet_len);
void free_rdata(struct rule_data *);
#ifdef lib_pcap_pcap_h
  void full_decode_libpcap(const unsigned char * user, const unsigned char * packet, const struct pcap_pkthdr * pkt_hdr);
#endif

/* DECODING FUNCTIONS */

// fully decode ethernet
void eth_decode(struct rule_data * rule);





/* Utilities */
// raw mac address to char array
unsigned char * mac_ntoa(const uint8_t * hw_addr);

// make address bytes to char array
unsigned char * uc_mac_ntoa(unsigned char * hw_addr);

// inet_ntoa but but for raw bytes
unsigned char * ipv4_ntoa(uint32_t ipv4addr);

// uin8_t[6] to char array
unsigned char * u8_ipv4_ntoa(uint8_t * ipv4addr);

// ipv4_nto but for ipv6
unsigned char * inet6_ntoa(uint8_t * ipv6addr);

// 12:23:34:45:56 to raw integer
void hw_addr_to_bytes(const char * str, uint8_t * output);
#endif /* VIGIL_H */