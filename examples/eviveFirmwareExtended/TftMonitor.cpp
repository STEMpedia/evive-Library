/*TftMonitor library implements similar view of serial monitor of Arduino desktop IDE
 *on evive TFT display.
 *
 *Last editted on  01.08.2017 by Harsh Chittora an Dhrupal R. Shah
 *Added support for double and float
 *Improved Text wrap for int  
 *
 *How to use:
 *1) Declare a class object with any name, say tftMonitor, as: TftMonitor tftMonitor;
 *2) Now you can use the tftMonitor as Serial object: tftMonitor.print(123)
 *
 *Note: Work in progress.
*/

#include "TftMonitor.h"
//	TftMonitor :: TftMonitor()
//	{
//		tft = TFT_ST7735();
//	}
 
	void TftMonitor :: begin()
	{
		//tft.init();
		//tft.setRotation(1);
//		Serial.println(tft.width());
//		Serial.println(tft.height());
		tft.fillRect(0, TOP_MARGIN, TFT_WIDTH, TFT_HEIGHT - TOP_MARGIN - BOTTOM_MARGIN, ST7735_BLACK);
		next_line = TOP_MARGIN;
		next_col = 0;
		tft.setTextColor(ST7735_RED,ST7735_BLACK);
		// change by nihar(tested and working) This adds ">" symbol at very beging of the first line.
		tft.setCursor(next_col,next_line);
		tft.print(">");
		next_col=next_col + CHAR_WIDTH;
	}

  void TftMonitor :: print(int i)
  {
		Serial.println("in print int");
  	/* 
		tft.fillRect(next_col, next_line, tft.width()-next_col, ROW_HEIGHT, ST7735_BLACK);
		tft.fillRect(0, next_line+ROW_HEIGHT, tft.width(), ROW_HEIGHT, ST7735_BLACK);
		tft.setCursor(next_col, next_line);
		if(next_col == 0)
			tft.print(">");
		tft.print(i);
		//next_line=next_line+8;
		if(next_col == 0) next_col = next_col + CHAR_WIDTH*(dig(i)+1);
		else next_col = next_col + CHAR_WIDTH*(dig(i));
		
		if(next_line >= TFT_HEIGHT-ROW_HEIGHT)
		  next_line = TOP_MARGIN;
		if(next_col > TFT_WIDTH-CHAR_WIDTH)
		{
				next_col = 0;
				next_line = next_line + ROW_HEIGHT;
		} */
		
  	s=String(i);
  	print(s);
  }
	
	// void	TftMonitor :: print(int i, int base){
		
	// }
	
/*    void TftMonitor :: println(int i)
   {
/* 		Serial.println("in println int");
		tft.fillRect(next_col, next_line, tft.width()-next_col, ROW_HEIGHT, ST7735_BLACK);
		tft.fillRect(0, next_line+ROW_HEIGHT, tft.width(), ROW_HEIGHT, ST7735_BLACK);
		tft.setCursor(next_col,next_line);
		if(next_col == 0)
			tft.print(">");
		tft.print(i);
		next_line=next_line + ROW_HEIGHT;
		//next_col=next_col+CHAR_WIDTH*dig(i);
		next_col = 0;
		if(next_line>TFT_HEIGHT-ROW_HEIGHT)
			next_line=TOP_MARGIN;
		if(next_col>TFT_WIDTH-CHAR_WIDTH)
		{
			next_col=0;
			next_line=next_line+ROW_HEIGHT;
		} 
  	s=String(i);
  	println(s);
#ifdef __DEBUG__
		Serial.println(freeRam());
#endif
   }	 */

  void TftMonitor :: print(char c)
  {
		Serial.println("in print char");
		Serial.print("Nex Col: ");
		Serial.print(next_col);
		Serial.print("\t Next Line: ");
		Serial.print(next_line);
		Serial.print("\t Char: ");
		Serial.print(c);
		
		tft.fillRect(next_col,next_line,CHAR_WIDTH*3,CHAR_HEIGHT,ST7735_BLACK);
		tft.setCursor(next_col,next_line);
		//tft.print(">");
		tft.print(c);
		//next_line=next_line+8;
		next_col=next_col + CHAR_WIDTH;
		
		if(next_line>114) //TFT_HEIGHT-ROW_HEIGHT)
		  next_line =TOP_MARGIN;
		if(next_col>TFT_WIDTH-CHAR_WIDTH)
		{
			if(next_line>=114)
			{	next_line=TOP_MARGIN;
				Serial.print("now next line = 0");
			}
			else
				next_line=next_line + ROW_HEIGHT;
			next_col=0;
			
					
		}

#ifdef __DEBUG__
		Serial.println(freeRam());
#endif
  }

  void TftMonitor :: print(double d)
  {
		Serial.println("in print d");
  	s=String(d);
  	print(s);
  	#ifdef __DEBUG__
  			Serial.println(freeRam());
  	#endif
  }

  void TftMonitor :: print(float f)
  {
		Serial.println("in print f");
  	s=String(f);
  	print(f);

  }

  void TftMonitor :: println(double d)
  {
		Serial.println("in println d");
  	s=String(d);
  	println(s);
  }

  void TftMonitor :: println(float f)
  {
		Serial.println("in println f");
  	s=String(f);
  	println(f);
  }
   
   void TftMonitor :: print(String s)
   {
		 Serial.println("in print str");
		for(int j=0;j<s.length();j++)
		{
			print(s[j]);
		}
   }
	 
/* 	size_t TftMonitor :: print(double number, uint8_t digits) 
{ 
  size_t n = 0;
  
  if (isnan(number)) return print("nan");
  if (isinf(number)) return print("inf");
  if (number > 4294967040.0) return print ("ovf");  // constant determined empirically
  if (number <-4294967040.0) return print ("ovf");  // constant determined empirically
  
  // Handle negative numbers
  if (number < 0.0)
  {
     n += print('-');
     number = -number;
  }

  // Round correctly so that print(1.999, 2) prints as "2.00"
  double rounding = 0.5;
  for (uint8_t i=0; i<digits; ++i)
    rounding /= 10.0;
  
  number += rounding;

  // Extract the integer part of the number and print it
  unsigned long int_part = (unsigned long)number;
  double remainder = number - (double)int_part;
  n += print(int_part);

  // Print the decimal point, but only if there are digits beyond
  if (digits > 0) {
    n += print("."); 
  }

  // Extract digits from the remainder one at a time
  while (digits-- > 0)
  {
    remainder *= 10.0;
    unsigned int toPrint = (unsigned int)(remainder);
    n += print(toPrint);
    remainder -= toPrint; 
  } 
  
  return n;
	} */
   
	void TftMonitor :: println(){
		Serial.println("in println _");
		//tft.fillRect(next_col +CHAR_WIDTH * 3, next_line, tft.width()-next_col, ROW_HEIGHT, ST7735_RED);
		tft.fillRect(0, next_line+ROW_HEIGHT, tft.width(), ROW_HEIGHT, ST7735_BLACK);
		
		//tft.print(i);
		next_line=next_line + ROW_HEIGHT;
		//next_col=next_col+CHAR_WIDTH*dig(i);
		next_col = 0;
		if(next_line>TFT_HEIGHT-ROW_HEIGHT)
			next_line=TOP_MARGIN;
		tft.setCursor(next_col,next_line);
		tft.print(">");
		next_col = CHAR_WIDTH;
  }
	
	//not working
  void  TftMonitor :: println(char c)
  {
		Serial.println("in println char");
		Serial.print("Nex Col: ");
		Serial.print(next_col);
		Serial.print("\t Next Line: ");
		Serial.print(next_line);
		Serial.print("\t Char: ");
		Serial.print(c);
		
/* 		tft.fillRect(next_col+2*CHAR_WIDTH,next_line,CHAR_WIDTH*3,CHAR_HEIGHT,ST7735_PINK);
		tft.setCursor(next_col+CHAR_WIDTH,next_line);
		//tft.print(">");
		tft.print(c);
		//next_line=next_line+8;
		next_col=next_col + CHAR_WIDTH;
		
			if(next_col>TFT_WIDTH-CHAR_WIDTH)
		{
			if(next_line>=114)
			{	next_line=TOP_MARGIN;
				Serial.print("now next line = 0");
			}
			else
				next_line=next_line + ROW_HEIGHT;
			next_col=0;
		} */
		print(c);
		println();			
		}
   
   void TftMonitor :: println(String s)
   {
		 /* Serial.println("in println str");
   		lines=(CHAR_WIDTH*s.length()/128)+1;
   		Serial.println(lines);
	   next_line=next_line + ROW_HEIGHT;
	   tft.fillRect(0,next_line,tft.width(), 2*lines*ROW_HEIGHT, ST7735_BLACK);
	   next_col=0;
	   // commented by nihar
	   print('>'); */
	   for(int j=0; j<s.length(); j++)
		{
			print(s[j]);
		}
		println();
   }
	 
	 void TftMonitor :: println(int i, int base)
   {
		 String _b = String(i,base);
		 print(_b);
		 println();
	 }
//TftMonitor tftMonitor;
