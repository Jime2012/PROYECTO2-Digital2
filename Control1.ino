
uint8_t info1;
uint8_t EstadoAdelate;
uint8_t EstadoAtras;


int Adelante = 11;
int Atras = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(Adelante, INPUT_PULLUP);  // We setup the PushButton's pins
  pinMode(Atras, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  info1 = 0;
  // put your main code here, to run repeatedly:
   EstadoAdelate = digitalRead(Adelante);    // We read the value of PB1 and store it in its indicated position
    EstadoAdelate = (!EstadoAdelate) << 1;
    EstadoAtras = digitalRead(Atras);    // We read the value of PB2 and store it in its indicated position 
    EstadoAtras = (!EstadoAtras) << 2;

    
    info1 |= EstadoAdelate;    //Store all controller information in the P1_Data Variable
    info1 |= EstadoAtras;
    Serial.write(info1);  //Send P1_Data to the master
    delay(100);
} 
