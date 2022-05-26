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

  unsigned char tcp_flags[8];                   // TCP flags in single character for such as
                                                //  "S" for SYN and "A" for ACK
  int is_established;                           // whether or not the tcp session is established
  
};
// Traffic flows
#define FLOW_OUTWARD                            69
#define FLOW_INWARD                             70
#define FLOW_EITHER                             71

void full_decode(const unsigned char * packet, const int packet_len);
#ifdef lib_pcap_pcap_h
  void full_decode_libpcap(const unsigned char * user, const unsigned char * packet, const struct pcap_pkthdr * pkt_hdr);
#endif



#endif /* VIGIL_H */