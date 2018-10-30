// Ajustando o PWM por HARDWARE na Raspberry Pi

#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 10kHz com 128 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 261 = 19200000 / (divisor * 245) => divisor = 300
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(50);                    // passos do duty cycle (max=4096)
   pwmSetClock(50);                     // fornece uma frequencia de 10kHz (max=4096)
   printf("Iniciando...\n");
   for ( dc = 0; dc < 25; dc++){
      pwmWrite(pino_PWM0, dc);
      printf("Valor: %d\n",dc);
      usleep(1000000);
   }
   pwmWrite(pino_PWM0, 0);
   return 0;
}