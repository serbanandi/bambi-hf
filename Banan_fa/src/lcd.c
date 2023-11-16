#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "bsp.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"
#include "bsp_trace.h"
#include "init_game.h"
#include "button.h"
#include "lcd.h"


void LCD_display ()
{
	//als� 14 szekmenses kijelz� plusz vez�rl�s�hez l�trehozott v�ltoz� kezdetben megszabadulunk a mem�ria szem�tt�l
	SegmentLCD_LowerCharSegments_TypeDef lowerseg [7] = {0}; //megfelel� szegmens aktiv�l�s�hoz a t�mbnek j� �rt�k ad�s

	SegmentLCD_AllOff(); //mindig �jra t�lt -mi nem l�tjuk elvileg

	for(uint8_t i=0; i<=level; i++)
	{
		SegmentLCD_ARing(i, 1); //megjelen�ti a neh�zs�gi szintet, kit�lti ameddig tart :)
	}

	//megjelen�tjuk az eredm�nyt, result fels� k�t helyi�rt�ke a sikereseket jelenti->100-al sz�molunk, az als� 2 a rontott esetek ezek egyesevel nonek xd
	SegmentLCD_Number(result);
	SegmentLCD_Symbol(LCD_SYMBOL_COL10, 1); //resulthoz kett�spont

	//�rt�k ad�s bin�risan, hogy k�nny� legyen, ban�n es�s �s kos�r helyzete
	if(game_started)
	{
		switch (banana_y)
		{
			case 0:
				lowerseg[banana_x].raw = 0b0000000000000001;
				break;
			case 1:
				lowerseg[banana_x].raw = 0b000000100000000;
				break;
			case 2:
				lowerseg[banana_x].raw = 0b001000000000000;
				break;
		}
			//basket
			// tov�bbi megfontol�st ig�nyel hogy mikor melyik szegmenssel kell �sszevagyolni a kosarat �s a ban�nt xd
			if(banana_x == basket)
			{
				lowerseg[banana_x].raw = lowerseg[banana_x].raw |  0b0000000000001000;
			}
			else
			{
				lowerseg[basket].raw = 0b0000000000001000; //3. bitet kell �ll�tani
			}

			SegmentLCD_LowerSegments(lowerseg); //friss�tj�k a k�perny�t

	}
}






