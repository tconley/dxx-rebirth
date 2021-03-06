/*
THE COMPUTER CODE CONTAINED HEREIN IS THE SOLE PROPERTY OF PARALLAX
SOFTWARE CORPORATION ("PARALLAX").  PARALLAX, IN DISTRIBUTING THE CODE TO
END-USERS, AND SUBJECT TO ALL OF THE TERMS AND CONDITIONS HEREIN, GRANTS A
ROYALTY-FREE, PERPETUAL LICENSE TO SUCH END-USERS FOR USE BY SUCH END-USERS
IN USING, DISPLAYING,  AND CREATING DERIVATIVE WORKS THEREOF, SO LONG AS
SUCH USE, DISPLAY OR CREATION IS FOR NON-COMMERCIAL, ROYALTY OR REVENUE
FREE PURPOSES.  IN NO EVENT SHALL THE END-USER USE THE COMPUTER CODE
CONTAINED HEREIN FOR REVENUE-BEARING PURPOSES.  THE END-USER UNDERSTANDS
AND AGREES TO THE TERMS HEREIN AND ACCEPTS THE SAME BY USE OF THIS FILE.
COPYRIGHT 1993-1999 PARALLAX SOFTWARE CORPORATION.  ALL RIGHTS RESERVED.
*/

/*
 *
 * Stuff for video clips.
 *
 */


#ifndef _VCLIP_H
#define _VCLIP_H

#include "gr.h"
#include "piggy.h"
#include "physfsx.h"

#ifdef __cplusplus
#include "dxxsconf.h"
#include "compiler-array.h"

struct object;
struct objptridx_t;

#define VCLIP_SMALL_EXPLOSION       2
#define VCLIP_PLAYER_HIT            1
#define VCLIP_MORPHING_ROBOT        10
#define VCLIP_PLAYER_APPEARANCE     61
#define VCLIP_POWERUP_DISAPPEARANCE 62
#define VCLIP_VOLATILE_WALL_HIT     5
#if defined(DXX_BUILD_DESCENT_I)
#define VCLIP_MAXNUM			70
#elif defined(DXX_BUILD_DESCENT_II)
#define VCLIP_WATER_HIT             84
#define VCLIP_AFTERBURNER_BLOB      95
#define VCLIP_MONITOR_STATIC        99

#define VCLIP_MAXNUM                110
#endif
#define VCLIP_MAX_FRAMES            30

// vclip flags
#define VF_ROD      1       // draw as a rod, not a blob

struct vclip
{
	fix             play_time;          // total time (in seconds) of clip
	unsigned        num_frames;
	fix             frame_time;         // time (in seconds) of each frame
	int             flags;
	short           sound_num;
	array<bitmap_index, VCLIP_MAX_FRAMES>    frames;
	fix             light_value;
};

extern unsigned Num_vclips;
#if defined(DXX_BUILD_DESCENT_I) || defined(DXX_BUILD_DESCENT_II)
extern array<vclip, VCLIP_MAXNUM> Vclip;
#endif

// draw an object which renders as a vclip.
void draw_vclip_object(object *obj, fix timeleft, int lighted, int vclip_num);
void draw_weapon_vclip(objptridx_t obj);

/*
 * reads n vclip structs from a PHYSFS_file
 */
void vclip_read(PHYSFS_file *fp, vclip &vc);
void vclip_write(PHYSFS_file *fp, const vclip &vc);

/* Defer expansion to source file so that serial.h not needed here */
#define DEFINE_VCLIP_SERIAL_UDT()	\
	DEFINE_SERIAL_UDT_TO_MESSAGE(bitmap_index, bi, (bi.index));	\
	DEFINE_SERIAL_UDT_TO_MESSAGE(vclip, vc, (vc.play_time, vc.num_frames, vc.frame_time, vc.flags, vc.sound_num, vc.frames, vc.light_value));	\
	ASSERT_SERIAL_UDT_MESSAGE_SIZE(vclip, 82);

#endif

#endif /* _VCLIP_H */
