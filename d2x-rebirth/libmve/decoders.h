/*
 *
 * INTERNAL header - not to be included outside of libmve
 *
 */

#ifndef _DECODERS_H
#define _DECODERS_H

#ifdef __cplusplus

extern int g_width, g_height;
extern unsigned char *g_vBackBuf1, *g_vBackBuf2;

extern void decodeFrame8(unsigned char *pFrame, unsigned char *pMap, int mapRemain, unsigned char *pData, int dataRemain);
extern void decodeFrame16(unsigned char *pFrame, unsigned char *pMap, int mapRemain, unsigned char *pData, int dataRemain);

#endif

#endif // _DECODERS_H
