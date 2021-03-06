#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0xA0,0xC9,0x8F,0x6D,0x75,0x7A,0x4E,0xED,0xED,0x80,0x11,0x32,
		0x77,0x14,0xEA,0xE0,0xE7,0x38,0x55,0x01,0x03,0x02,0xC5,0x34,
		0xCA,0x2D,0xA7,0xFA,0x2E,0x1C,0x5F,0xD9,0xF4,0xDA,0x54,0x40,
		0xD7,0xB4,0x7B,0x00,0xE5,0x19,0x30,0x69,0xC5,0x93,0x52,0x09,
		0xB7,0x2D,0x5B,0xAB,0x27,0x0C,0x0D,0xAA,0xCE,0x56,0xB7,0x4D,
		0xE9,0x8A,0xFB,0x43,
		};
	static unsigned char dh512_g[]={
		0x02,
		};
	DH *dh;

	if ((dh=DH_new()) == NULL) return(NULL);
	dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
	dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
	if ((dh->p == NULL) || (dh->g == NULL))
		{ DH_free(dh); return(NULL); }
	return(dh);
	}
