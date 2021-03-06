/******************************************************************************

	psp.c

	PSP・皈、・□

******************************************************************************/

#ifndef PSP_MAIN_H
#define PSP_MAIN_H

#ifndef MAX_PATH
#define MAX_PATH 256
#endif

#include "emucfg.h"

#include <psptypes.h>
#include "include/osd_cpu.h"
#include <pspaudio.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include <pspiofilemgr.h>
#include <pspkernel.h>
#include <psppower.h>
#include <psprtc.h>
#include <pspsdk.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/unistd.h>
#include <ctype.h>

#include "psp/ui_text.h"
#include "psp/filer.h"
#include "psp/input.h"
#include "psp/ticker.h"
#include "psp/video.h"
#include "psp/sound.h"

#if (EMU_SYSTEM == NCDZ)
#include "psp/mp3.h"
#endif

enum
{
	LOOP_EXIT = 0,
	LOOP_BROWSER,
	LOOP_RESTART,
	LOOP_RESET,
	LOOP_EXEC
};

enum
{
	PSPCLOCK_222 = 0,
	PSPCLOCK_266,
	PSPCLOCK_300,
	PSPCLOCK_333,
	PSPCLOCK_MAX
};

extern volatile int Loop;
extern volatile int Sleep;
extern char launchDir[MAX_PATH];

int get_free_space(void);
int get_max_free_block_size(void);

void display_free_space(void);
void display_max_free_block_size(void);
void display_available_memory(void);

#endif /* PSP_MAIN_H */
