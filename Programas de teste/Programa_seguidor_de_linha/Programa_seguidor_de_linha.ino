
/*--------------------------------------------------------------------
 * ROBO SEGUINDO A LINHA BRANCA E PARANDO QUANDO ALGUEM ESTIVER NA FRENTE
 * 
 * -------------------------------------------------------------------*/

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

// Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 9;
const int dirpin1 = 13;
const int dirpin2 = 11;

//Variável para o controle do loop for
int x = 0;

//Declarações para sensor seguidor de linha
const int linha_d1 = 1;  //Sensor fora da linha
const int linha_d2 = 2;  //Sensor fora da linha
const int linha_d3 = 3;     //*____ Sensor dentro da linha ____*
const int linha_d4 = 4;     //      Senso dentro da linha
const int linha_d5 = 5;     //      Sensor dentro da linha
const int linha_d6 = 6;     //*____ Sensor dentro da linha ____*
const int linha_d7 = 7;  //Sensor fora da linha
const int linha_d8 = 8;  //Sensor fora da linha


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


//Variaveis de controle de distância dos sensores ultrasônicos
float cmMsec;
float cmMsec_direita;
float cmMsec_esquerda;

//Variavel de controle para parar o robo

bool stop_agv = false;

void setup() {
  //Declaração de IO, pulso dos dois motores, e a direção dos dois motores
  pinMode(steppin1, OUTPUT);
  pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);

  //Declarando as entradas dos sensores seguidor de linhas
  pinMode(linha_d1, INPUT);
  pinMode(linha_d2, INPUT);
  pinMode(linha_d3, INPUT);
  pinMode(linha_d4, INPUT);
  pinMode(linha_d5, INPUT);
  pinMode(linha_d6, INPUT);
  pinMode(linha_d7, INPUT);
  pinMode(linha_d8, INPUT);

  

}
// -- STRAT VOID LOOP --
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


  /*--------------------------------------------------------------------
 * LÓGICA PARA SE IDENTIFICAR ALGO PELOS SENSORES ULTRASÔNICOS   
 * 
 * -------------------------------------------------------------------*/
    // Se o robô identificar algo na sua frente, setar a variavel de controle para para o robo
    if(cmMsec <= 60 || cmMsec_direita <= 60 || cmMsec_esquerda <= 60)
    {
      stop_agv = true;
    }
    else     // Se não a variavel de controle irar liberar ele para continuar andando
    {
      stop_agv = false;
    }
  
/*--------------------------------------------------------------------
 * LÓGICA PARA O ROBÔ SEGUIR A LINHA  
 * 
 * -------------------------------------------------------------------*/


  // Se todos os sensores centrais, conseguirem detectar a linha, e a variavel de controle false, então mover o robo para frente
  if ( !stop_agv && digitalRead(linha_d3) && digitalRead(linha_d4) && digitalRead(linha_d5) && digitalRead(linha_d6) )
  {
    moveForward(); //Mover para frente
  }

  // Se um dos sensores da esquerda indentificar a linha, então firar para a direita
  if ( !stop_agv && (digitalRead(linha_d1) || digitalRead(linha_d2)) )
  {
    turnRight(); //Virar para direita
  }

  if ( !stop_agv && (digitalRead(linha_d7) || digitalRead(linha_d8)) )
  {
    turnLeft(); //Viara para Esquerda
  }

}
// -- END VOID LOOP --


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
