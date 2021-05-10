
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

  // Se o robô identificar algo na sua frente, ele ira virar
  if(cmMsec <= 60)
  {
    delay(100);
    turnLeft();
    delay(100);
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
  for(x = 0; x < 1000; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
  }
}
