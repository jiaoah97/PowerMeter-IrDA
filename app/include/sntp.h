#ifndef __SNTP_H__
#define __SNTP_H__

#include "lwip/ip_addr.h"
#include <localtime.h>

bool sntp_inits(int8_t UTC_offset, uint16_t update_delay_min, char * srv) ICACHE_FLASH_ATTR;
void sntp_close(void) ICACHE_FLASH_ATTR;
time_t get_sntp_time(void) ICACHE_FLASH_ATTR;
time_t get_sntp_localtime(void) ICACHE_FLASH_ATTR;
time_t sntp_local_to_UTC_time(time_t local) ICACHE_FLASH_ATTR;
void sntp_set_time(time_t t) ICACHE_FLASH_ATTR;

extern ip_addr_t dhcp_sntp_server_address;
extern int16_t sntp_time_adjust; // sec
extern int8 sntp_status; // 1,2 = ok, -1 = manual set
extern uint32 sntp_update_delay; // us

void sntp_send_request(ip_addr_t *server_addr) ICACHE_FLASH_ATTR;

#endif /* __SNTP_H__ */
