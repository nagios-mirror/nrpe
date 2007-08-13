#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0xBD,0x3F,0xF2,0xBB,0x91,0x8A,0x6D,0x31,0xF8,0xD2,0xBE,0xA1,
		0x43,0x40,0x5D,0xAD,0x66,0xC6,0x83,0x16,0xC7,0x7F,0xD3,0x13,
		0xC6,0x15,0xB0,0x4B,0x98,0x8E,0xF1,0x65,0x4E,0x30,0x24,0x27,
		0x6D,0xCA,0x0D,0x23,0x52,0x19,0x2E,0x56,0xFA,0x3F,0x53,0x6A,
		0x58,0x08,0xB8,0x6A,0x30,0x14,0xF2,0x65,0x12,0x4F,0xD8,0x74,
		0x1E,0x82,0x4F,0x3B,
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
