
/*--------------------------------------------------------------------
 * ROBO ANDA PARA FRENTE, E QUANDO ENCONTRAR ALGO, ELE GIRA 90ª
 * 
 * -------------------------------------------------------------------*/

 
//Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 9;
const int dirpin1 = 13;
const int dirpin2 = 11;
int x = 0;


void setup() 
{
  //Iniciando monitor serial
  Serial.begin(9600);

  //declaração de IO
  pinMode(steppin1, OUTPUT);
  pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);
}

void loop() 
{
  //Recebendo uma letra do Serial
  char c = Serial.read();

  if (c == 'a')
  {
    moveForward();
  }

  if (c == 'b')
  {
    moveBack();
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
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for(x = 0; x < 3600; x++) {
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
  delay(1);

  //Mandando os pulsos para o driver mover os motores
  for(x = 0; x < 3600; x++) {
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
  for(x = 0; x < 3600; x++) {
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
  for(x = 0; x < 3600; x++) {
      digitalWrite(steppin1, HIGH);
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
  }
}
