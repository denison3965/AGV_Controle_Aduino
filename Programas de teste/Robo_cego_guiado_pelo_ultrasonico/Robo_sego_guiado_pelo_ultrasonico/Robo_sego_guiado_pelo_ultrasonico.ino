
/*--------------------------------------------------------------------
 * ROBO ANDA PARA FRENTE, E QUANDO ENCONTRAR ALGO, ELE GIRA 90ª
 * 
 * -------------------------------------------------------------------*/
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

// Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 9;
const int dirpin1 = 13;
const int dirpin2 = 11;
int x = 0;


//Define os pinos para o trigger e echo do Ultrasônico da frente
#define pino_trigger 4
#define pino_echo 5

//Define os pinos para o trigger e echo do Ultrasônico da direita
#define pino_trigger2 3
#define pino_echo2 2


//Define os pinos para o trigger e echo do Ultrasônico da esqueda
#define pino_trigger3 8
#define pino_echo3 6 

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic_direita(pino_trigger2, pino_echo2);

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic_esquerda(pino_trigger3, pino_echo3);



float cmMsec;
float cmMsec_direita;
float cmMsec_esquerda;


void setup() {
  // Iniciando monitor serial
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");

  //declaração de IO, pulso dos dois motores, e a direção dos dois motores
  pinMode(steppin1, OUTPUT);
  pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);


}

void loop() {
  //Lendo as informações do sensor ultrasônico, em cm
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

    //Lendo as informações do sensor ultrasônico, em cm
  float cmMsec_direita;
  long microsec_direita = ultrasonic_direita.timing();
  cmMsec_direita = ultrasonic_direita.convert(microsec_direita, Ultrasonic::CM);

    //Lendo as informações do sensor ultrasônico, em cm
  float cmMsec_esquerda;
  long microsec_esquerda = ultrasonic_esquerda.timing();
  cmMsec_esquerda = ultrasonic_esquerda.convert(microsec_esquerda, Ultrasonic::CM);

  // Se o robô identificar algo na sua frente, ele ira virar
  if(cmMsec <= 60 || cmMsec_direita <= 60 || cmMsec_esquerda <= 60)
  {
    delay(1500);
    turnLeft();
    delay(1500);
  }
  else
  {
    moveForward();
  }

}


/*--------------------------------------------------------------------
 * FUNÇÔES PARA FAZER O ROBO SE MOVER EM DIVERSAS DIREÇOES
 * 
 * -------------------------------------------------------------------*/


//FUNÇÃO PARA ANDAR PARA A FRENTE
void moveForward()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, HIGH);


  //Mandando os pulsos para o driver mover os motores

    for(x = 0; x < 100; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
    }


  
  
}

//FUNÇÃO PARA ANDAR PARA A TRÀS
void moveBack()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, HIGH);
  digitalWrite(dirpin2, LOW);


  //Mandando os pulsos para o driver mover os motores
  for(x = 0; x < 100; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
  }
}

//FUNÇÃO PARA VIRAR A DIREITA
void turnRight()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, LOW);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for(x = 0; x < 1000; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
  }  
}

//FUNÇÃO PARA VIRAR A ESQUERDA
void turnLeft()
{
  //Setando a direção de rotação de cada motor
  digitalWrite(dirpin1, HIGH);
  digitalWrite(dirpin2, HIGH);
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for(x = 0; x < 500; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
  }
}
