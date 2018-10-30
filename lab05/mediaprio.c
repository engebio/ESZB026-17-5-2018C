// Ajustando o PWM por HARDWARE na Raspberry Pi

#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 10kHz com 245 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 10000 = 19200000 / (divisor * 245) => divisor = 300
   pwmSetMode(PWM_MODE_MS);             
   pwmSetRange(245);                    
   pwmSetClock(300);                     
   printf("Iniciando...\n");
   dc=122;
   int tempo = 200000;
   pwmWrite(pino_PWM0, dc);
   usleep(tempo);
   pwmWrite(pino_PWM0, 0);
   usleep(tempo);
   pwmWrite(pino_PWM0, dc);
   usleep(tempo);
   pwmWrite(pino_PWM0, 0);
   usleep(tempo);
   pwmWrite(pino_PWM0, dc);
   usleep(tempo);
   pwmWrite(pino_PWM0, 0);



   printf("Fim.\n");
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
