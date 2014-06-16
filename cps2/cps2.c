/******************************************************************************

	cps2.c

	CPS2・ィ・゜・螂□`・キ・逾□ウ・「

******************************************************************************/

#include "cps2.h"


/******************************************************************************
	・□`・ォ・□vハ□
******************************************************************************/

/*--------------------------------------------------------
	CPS2・ィ・゜・螂□`・キ・逾□□レサッ
--------------------------------------------------------*/

static int cps2_init(void)
{
	if (!cps2_driver_init())
		return 0;

	msg_printf(TEXT(DONE2));

	return cps2_video_init();
}


/*--------------------------------------------------------
	CPS2・ィ・゜・螂□`・キ・逾□□サ・テ・ネ
--------------------------------------------------------*/

void cps2_reset(void)
{
	Loop = LOOP_EXEC;

	cps2_driver_reset();
	cps2_video_reset();

	timer_reset();
	input_reset();
	sound_reset();

	blit_clear_all_sprite();
}

/*--------------------------------------------------------
	CPS・ィ・゜・螂□`・キ・逾□Kチヒ
--------------------------------------------------------*/

void cps2_exit(void)
{
	msg_printf(TEXT(PLEASE_WAIT2));
	cps2_driver_exit();
   sound_exit();
   memory_shutdown();
	msg_printf(TEXT(DONE2));
}



int cps2_main(void)
{
   if (memory_init())
   {
      if (sound_init())
      {
         if (input_init())
         {
            if (cps2_init())
            {
               cps2_reset();
               return 1;
            }
            cps2_driver_exit();
         }
      }
      sound_exit();
   }
   memory_shutdown();
   return 0;
}
