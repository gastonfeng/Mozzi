#ifndef AUDIOCONFIGHISPEED14BITPWM_H
#define AUDIOCONFIGHISPEED14BITPWM_H

/*
14 bit sound at 16384 Hz and 125kHz pwm rate
Timer 1: PWM 125kHz 
Timer 2: called at AUDIO_RATE 16384 Hz, setting Timer1 pwm levels
Output on Timer1, low byte on Pin 10, and high byte on Pin 9 (on 328 based Arduino boards)
Add signals through a 3.9k resistor on high byte pin and 499k resistor on low byte pin.
Use 0.5% resistors or select the most accurate from a batch.
As discussed on http://www.openmusiclabs.com/learning/digital/pwm-dac/dual-pwm-circuits/
Also, there are higher quality output circuits are on the site.

Boards, pins and resistor positions are documented in MozziGuts.h
*/

// pins defined in TimerOne/config/known_16bit_timers.h
#define AUDIO_CHANNEL_1_HIGHBYTE_PIN TIMER1_A_PIN // 3.9k resistor
#define AUDIO_CHANNEL_1_LOWBYTE_PIN TIMER1_B_PIN // 1 M resistor
#define AUDIO_CHANNEL_1_HIGHBYTE_REGISTER OCR1AL
#define AUDIO_CHANNEL_1_LOWBYTE_REGISTER OCR1BL

/* Used internally for HIFI mode, for pwm freq of TimerOne */
#define PWM_RATE 65536

/** @ingroup core
This is the dynamic range of Mozzi's audio output on each of the dual output pins in HIFI mode.
It is equal to the F_CPU rate of 16000000 divided by a PWM_RATE of 65536.
It's included in the documentation because it's a slightly unusual number, and useful to know 
about when you're writing sketches.
*/
#define HIFI_PWM_RESOLUTION 244


/* Used internally to put the 0-biased generated audio into the right range for PWM output.*/
// 14 bit
#define AUDIO_BIAS ((unsigned int) 0x2000)


#endif        //  #ifndef AUDIOCONFIGHISPEED14BITPWM_H

