#include <VirtualWire.h>
//https://www.youtube.com/watch?v=cplAjvAAEDw
//http://myhowtosandprojects.blogspot.pt/2014/01/arduino-rf-transmitter-receiver-mx-fs.html


int count = 0;
char buf[12];
void setup() 
{ 
    // Initialize the IO and ISR 
    pinMode(13, OUTPUT);
    vw_setup(2000); // Bits per sec 
}

void loop() 
{ 
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);    
  itoa(count++, buf, 10);
    send("Hello there");
  delay(1000);    
    send(buf); 
}

void send (char *message) 
{ 
    vw_send((uint8_t *)message, strlen(message)); 
    vw_wait_tx(); // Wait until the whole message is gone 
}
