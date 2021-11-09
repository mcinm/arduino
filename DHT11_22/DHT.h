#define DHT_GPIO 0

void request(void)
{
  pinMode(DHT_GPIO, OUTPUT);
  digitalWrite(DHT_GPIO, LOW);
  delay(20);
  digitalWrite(DHT_GPIO, HIGH);
  delayMicroseconds(35);
}

void response(void)
{
  pinMode(DHT_GPIO, INPUT);
  while (digitalRead(DHT_GPIO));
  while (!(digitalRead(DHT_GPIO)));
  while (digitalRead(DHT_GPIO));	
}

unsigned char get_data(void)
{
  unsigned char data = 0;
  for (unsigned char i=0; i<8; i++)
  {
    while (!(digitalRead(DHT_GPIO)));
    delayMicroseconds(30);
    if (digitalRead(DHT_GPIO)) data = (data<<1) | (0x01);
    else data = (data<<1);
    while (digitalRead(DHT_GPIO));
  }
  return data;
}
