
/*--------------------------------------------------------------------
 * ROBO SEGUINDO A LINHA BRANCA E PARANDO QUANDO ALGUEM ESTIVER NA FRENTE
 * 
 * -------------------------------------------------------------------*/

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>


//Declarações para sensor seguidor de linha
const int linha_d1 = 1;  //Sensor fora da linha
const int linha_d2 = 2;  //Sensor fora da linha
const int linha_d3 = 3;     //*____ Sensor dentro da linha ____*
const int linha_d4 = 4;     //      Senso dentro da linha
const int linha_d5 = 5;     //      Sensor dentro da linha
const int linha_d6 = 6;     //*____ Sensor dentro da linha ____*
const int linha_d7 = 7;  //Sensor fora da linha
const int linha_d8 = 8;  //Sensor fora da linha

// Declaraçôes para os enviar para centro de controle
const int controller_moveForward = 9;
const int controller_moveBack = 10;
const int controller_turnRight = 11;
const int controller_turnLeft = 12;

//Define os pinos para o trigger e echo do Ultrasônico da frente
#define pino_trigger 13
#define pino_echo 14

//Define os pinos para o trigger e echo do Ultrasônico da direita
#define pino_trigger2 15
#define pino_echo2 16


//Define os pinos para o trigger e echo do Ultrasônico da esqueda
#define pino_trigger3 17
#define pino_echo3 18


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

  //Declarando as entradas dos sensores seguidor de linhas
  pinMode(linha_d1, INPUT);
  pinMode(linha_d2, INPUT);
  pinMode(linha_d3, INPUT);
  pinMode(linha_d4, INPUT);
  pinMode(linha_d5, INPUT);
  pinMode(linha_d6, INPUT);
  pinMode(linha_d7, INPUT);
  pinMode(linha_d8, INPUT);

  
  //Declarando os controlles para controle de direção do ADV (comunicação entre informação e controle)
  pinMode(controller_moveForward, OUTPUT);
  pinMode(controller_moveBack, OUTPUT);
  pinMode(controller_turnRight, OUTPUT);
  pinMode(controller_turnLeft, OUTPUT);

  

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
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveBack,  LOW );
        digitalWrite(controller_turnRight, LOW );
        digitalWrite(controller_turnLeft,  LOW );
    //---
    digitalWrite(controller_moveForward, HIGH); //Mover para frente
  }

  // Se um dos sensores da esquerda indentificar a linha, então firar para a direita
  if ( !stop_agv && (digitalRead(linha_d1) || digitalRead(linha_d2)) )
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveBack,  LOW );
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnLeft,  LOW );
    //---
    digitalWrite(controller_turnRight, HIGH); //Virar para Direita
  }

  if ( !stop_agv && (digitalRead(linha_d7) || digitalRead(linha_d8)) )
  {
    //Manda para os controladores para qualquer outro comando nos drivers dos motores
    //----
        digitalWrite(controller_moveBack,  LOW );
        digitalWrite(controller_moveForward, LOW );
        digitalWrite(controller_turnRight,  LOW );
    //---
    digitalWrite(controller_turnLeft, HIGH); //Viara para Esquerda
  }

}
// -- END VOID LOOP --
