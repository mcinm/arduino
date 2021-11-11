#include "DHT.h"

unsigned char tab[5];


// After this function data are ready to use
void get_mes(void)
{
  request();
  response();
  
  tab[0] = get_data();
  tab[1] = get_data();
  tab[2] = get_data();
  tab[3] = get_data();
  tab[4] = get_data();
  
  unsigned char control = tab[0] + tab[1] + tab[2] + tab[3];
  if (control != tab[4]) get_mes();
}


void setup()
{

}


void loop()
{

}
