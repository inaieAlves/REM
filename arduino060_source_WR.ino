/*
   Curso de Arduino e AVR WR Kits Channel
   
   Aula 60 - Software para Controle de Potência AC
   
   Aula complementar: https://www.youtube.com/watch?v=v1FAvLzIQPA
   
    
   Autor: Eng. Wagner Rambo  Data: Março de 2016
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits
   
*/


// --- Mapeamento de Hardware ---
#define   pot       A0
#define   but        8
#define   out       13


// --- Variáveis Globais ---
int time  = 0x00,                              //Variável para o tempo de disparo
    angle = 0x0A;                              //Variável para o ângulo de disparo


// --- Rotina de Interrupção ---
void interrupt()
{
    
    for(int i=0; i<time; i++)
    {
    
       delay(2);
    }
    digitalWrite(out, HIGH);
    delay(1);
    digitalWrite(out, LOW);

} //end interrupt


// --- Configurações Iniciais ---
void setup()
{
   pinMode(2, INPUT);      //entrada INT0
   pinMode(out, OUTPUT);    //saída digital 13
   
   digitalWrite(out, LOW);

   attachInterrupt(0, interrupt, RISING);
   
}


// --- Loop Infinito ---
void loop()
{
   //aguardando a interrupção...
     angle = 90;
    
     time = (angle*8.33)/180;                //Equação para o cálculo do tempo

}

