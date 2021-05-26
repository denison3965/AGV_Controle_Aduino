/*--------------------------------------------------------------------
 * ROBO SEGUINDO A LINHA BRANCA (CONTROLADOR DOS DIVRES DOS MOTORES)
 * CENTRO DE CONTROLE (MOVIMENTO DO ROBÔ)
 * 
 * -------------------------------------------------------------------*/
// Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 9;
const int dirpin1 = 13;
const int dirpin2 = 11;

// Declaraçôes para os ouvidores do centro de informações
const int controller_moveForward = 1;
const int controller_moveBack = 2;
const int controller_turnRight = 3;
const int controller_turnLeft = 4;

//Variável para o controle do loop for
int x = 0;


void setup() {
  //Declaração de IO, pulso dos dois motores, e a direção dos dois motores
  pinMode(steppin1, OUTPUT);
  pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);

  //Declarando os ouvidores para controle de direção do ADV (comunicação entre informação e controle)
  pinMode(controller_moveForward, INPUT);
  pinMode(controller_moveBack, INPUT);
  pinMode(controller_turnRight, INPUT);
  pinMode(controller_turnLeft, INPUT);

}

void loop() {
  //Fazendo com que o robo ande, dependendo do controlador que estiver ativado
  while( digitalRead(controller_moveForward) )
  {
    moveForward();
  }

  while( digitalRead(controller_moveBack) )
  {
    moveBack();
  }

  while( digitalRead(controller_turnRight) )
  {
    moveForward();
  }

  while( digitalRead(controller_turnLeft) )
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
  for(x = 0; x < 50; x++) {
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
  for(x = 0; x < 50; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
  }
}
