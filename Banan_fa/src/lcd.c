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
	//alsó 14 szekmenses kijelzõ plusz vezérléséhez létrehozott változó kezdetben megszabadulunk a memória szeméttõl
	SegmentLCD_LowerCharSegments_TypeDef lowerseg [7] = {0}; //megfelelõ szegmens aktiválásához a tömbnek jó érték adás

	SegmentLCD_AllOff(); //mindig újra tölt -mi nem látjuk elvileg

	for(uint8_t i=0; i<=level; i++)
	{
		SegmentLCD_ARing(i, 1); //megjeleníti a nehézségi szintet, kitölti ameddig tart :)
	}

	//megjelenítjuk az eredményt, result felsõ két helyiértéke a sikereseket jelenti->100-al számolunk, az alsó 2 a rontott esetek ezek egyesevel nonek xd
	SegmentLCD_Number(result);
	SegmentLCD_Symbol(LCD_SYMBOL_COL10, 1); //resulthoz kettõspont

	//érték adás binárisan, hogy könnyû legyen, banán esés és kosár helyzete
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
			// további megfontolást igényel hogy mikor melyik szegmenssel kell összevagyolni a kosarat és a banánt xd
			if(banana_x == basket)
			{
				lowerseg[banana_x].raw = lowerseg[banana_x].raw |  0b0000000000001000;
			}
			else
			{
				lowerseg[basket].raw = 0b0000000000001000; //3. bitet kell állítani
			}

			SegmentLCD_LowerSegments(lowerseg); //frissítjük a képernyõt

	}
}






