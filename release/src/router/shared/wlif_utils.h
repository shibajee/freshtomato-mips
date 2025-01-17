/*
 * Shell-like utility functions
 *
 * Copyright (C) 2008, Broadcom Corporation
 * All Rights Reserved.
 * 
 * THIS SOFTWARE IS OFFERED "AS IS", AND BROADCOM GRANTS NO WARRANTIES OF ANY
 * KIND, EXPRESS OR IMPLIED, BY STATUTE, COMMUNICATION OR OTHERWISE. BROADCOM
 * SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A SPECIFIC PURPOSE OR NONINFRINGEMENT CONCERNING THIS SOFTWARE.
 *
 * $Id: wlif_utils.h,v 1.3 2008/09/17 23:10:05 Exp $
 */

#ifndef _wlif_utils_h_
#define _wlif_utils_h_

#ifndef IFNAMSIZ
#define IFNAMSIZ 16
#endif

#ifndef ETHER_ADDR_LEN
#define ETHER_ADDR_LEN 6
#endif

#define WLIFU_MAX_NO_BRIDGE	4
#define WLIFU_MAX_NO_WAN	2

#define MAX_USER_KEY_LEN	80		/* same as NAS_WKSP_MAX_USER_KEY_LEN */
#define MAX_SSID_LEN		32		/* same as DOT11_MAX_SSID_LEN */

typedef struct wsec_info_s {
	int unit;				/* interface unit */
	int ibss;				/* IBSS vs. Infrastructure mode */
	int gtk_rekey_secs;			/* group key rekey interval */
	int wep_index;				/* wep key index */
	int ssn_to;				/* ssn timeout value */
	int debug;				/* verbose - 0:no | others:yes */
	int preauth;				/* preauth */
	int auth_blockout_time;			/* update auth blockout retry interval */
	unsigned int auth;			/* shared key authentication optional (0) or required (1) */
	unsigned int akm;			/* authentication mode */
	unsigned int wsec;			/* encryption */
	unsigned int flags;			/* flags */
	char osifname[IFNAMSIZ];		/* interface name */
	unsigned char ea[ETHER_ADDR_LEN];	/* interface hw address */
	unsigned char remote[ETHER_ADDR_LEN];	/* wds remote address */
	unsigned short radius_port;		/* radius server port number */
	char ssid[MAX_SSID_LEN + 1];		/* ssid info */
	char psk[MAX_USER_KEY_LEN + 1];		/* user-supplied psk passphrase */
	char *secret;				/* user-supplied radius secret */
	char *wep_key;				/* user-supplied wep key */
	char *radius_addr;			/* radius server address */
	char *nas_id;				/* nas mac address */
} wsec_info_t;

#define WLIFU_WSEC_SUPPL	0x00000001	/* role is supplicant */
#define WLIFU_WSEC_AUTH		0x00000002	/* role is authenticator */
#define WLIFU_WSEC_WDS		0x00000004	/* WDS mode */

#define WLIFU_AUTH_RADIUS	0x20		/* same as nas_mode_t RADIUS in nas.h */

/* get wsec return code */
#define WLIFU_WSEC_SUCCESS		0
#define WLIFU_ERR_INVALID_PARAMETER	1
#define WLIFU_ERR_NOT_WL_INTERFACE	2
#define WLIFU_ERR_NOT_SUPPORT_MODE	4
#define WLIFU_ERR_WL_REMOTE_HWADDR	3
#define WLIFU_ERR_WL_WPA_ROLE		5

extern int get_spoof_mac(const char *osifname, char *mac, int maclen);
extern int get_spoof_ifname(char *mac, char *osifname, int osifnamelen);
extern int get_real_mac(char *mac, int maclen);
extern int get_lan_mac(unsigned char *mac);
extern unsigned char *get_wlmacstr_by_unit(char *unit);
extern int get_wlname_by_mac(unsigned char *mac, char *wlname);
extern char *get_ifname_by_wlmac(unsigned char *mac, char *name);

extern int get_wsec(wsec_info_t *info, unsigned char *mac, char *osifname);

#endif /* _wlif_utils_h_ */
