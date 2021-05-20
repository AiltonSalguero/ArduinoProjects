const int TriggerOne = 2;   //Pin digital 2 para el Trigger del sensor 1
const int EchoOne = 3;   //Pin digital 3 para el Echo del sensor 1
const int TriggerTwo = 5;   //Pin digital 3 para el Trigger del sensor 2
const int EchoTwo = 6;   //Pin digital 6 para el Echo del sensor 2

void setup() {
  Serial.begin(9600);
  // Definicion de pines
  pinMode(TriggerOne, OUTPUT);
  pinMode(EchoOne, INPUT);
  digitalWrite(TriggerOne, LOW);//Inicializamos el pin con 0

  pinMode(TriggerTwo, OUTPUT);
  pinMode(EchoTwo, INPUT);
  digitalWrite(TriggerTwo, LOW);//Inicializamos el pin con 0
}

void loop()
{
  // Tiempo que demora en llegar el eco
  long t1;
  long t2;
  // Distancia en centimetros
  long d1;
  long d2;

  // Primer sensor
  digitalWrite(TriggerOne, HIGH);
  delayMicroseconds(10);          // Pulso de 10us
  digitalWrite(TriggerOne, LOW);

  t1 = pulseIn(EchoOne, HIGH); // Ancho del pulso
  d1 = t1 / 59;           // Escalado a cm

  // Segundo sensor
  digitalWrite(TriggerTwo, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerTwo, LOW);

  t2 = pulseIn(EchoTwo, HIGH);
  d2 = t2 / 59;
  Serial.print(d1);
  Serial.print("-");
  Serial.print(d2);
  Serial.println();

  // Delay de 1.5 segundos
  delay(1500);
}
