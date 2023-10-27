char dato;
char prevDato;

void setup()  
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop(){
  if (Serial.available()){
    char prevDato = dato;
    char dato = Serial.read();
    if(dato != prevDato){
    Serial.print("Dato recibido: ");
    Serial.println(dato);
    switch (dato){
        case 'F':
          front();
          break;
        case 'R':
          right();
          break;
        case 'L':
          left();
          break;
        case 'B':
          back();
          break;
        case 'S':
          stop();
          break;
        default:
          stop();
    }
  }
}
}

void front(){
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  analogWrite(3, 235);  
  
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  analogWrite(2, 235);
  Serial.println("front");
}

void stop(){
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  analogWrite(3, 235);   
  
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  analogWrite(2,235);
  Serial.println("stops");
}

void right(){
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  analogWrite(3, 235);   
  
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  analogWrite(2,235);
  Serial.println("right");
  }

void left(){
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  analogWrite(3, 235);   
  
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  analogWrite(2,235);
  Serial.println("left");
}

void back(){
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  analogWrite(3, 235);   
  
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  analogWrite(2,235);
  Serial.println("backs");
}