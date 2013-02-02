/**
 * Text To Speech synthesis library
 * Copyright (c) 2008 Clive Webster.  All rights reserved.
 *
 * Nov. 29th 2009 - Modified to work with Arduino by Gabriel Petrut:
 * The Text To Speech library uses Timer1 to generate the PWM
 * output on digital pin 10. The output signal needs to be fed
 * to an RC filter then through an amplifier to the speaker.
 * http://www.tehnorama.ro/minieric-modulul-de-control-si-sinteza-vocala/
 *
 * Modified to allow use of different PWM pins by Stephen Crane.
 */
#include <TTS.h>

// Media pins
#define PWM 3
#define LED 13                          

TTS text2speech(PWM);  // default is digital pin 10

void setup() { 
  pinMode(LED, OUTPUT); 
}

void loop() {
  digitalWrite(LED, !digitalRead(LED));

  text2speech.setPitch(6); //higher values = lower voice pitch
  text2speech.say("Hello  master! How are you doin?");
  delay(500); 

  text2speech.setPitch(1); //lower values = higher voice pitch
  text2speech.say("I am fine, thankyou."); 

  delay(1000);
}  
