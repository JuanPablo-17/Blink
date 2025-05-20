// Def pines del motor del primer nivel (experimental)
const int IN1 = 14;
const int IN2 = 27;
const int IN3 = 26;
const int IN4 = 25;

//Def Pines motor nivel superior(Experimental) 
const int gpio1 = 21;
const int gpio2 = 19;
const int gpio3 = 18;
const int gpio4 = 17; 

int paso[4][4] = {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

int motorSuperior[4][4] = {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(gpio1, OUTPUT);
  pinMode(gpio2, OUTPUT);
  pinMode(gpio3, OUTPUT);
  pinMode(gpio4, OUTPUT);
}

void loop() {
  // Hacia adelante
  for (int vueltas = 0; vueltas < 256; vueltas++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(10);
    }
  }

  delay(500);

  // Hacia atrás
  for (int vueltas = 0; vueltas < 256; vueltas++) {
    for (int i = 3; i >= 0; i--) {
      digitalWrite(IN1, paso[i][0]);
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(10);
    }
  }

  delay(1000);  // Espera antes de repetir

  for (int vueltas = 0; vueltas < 128; vueltas++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(gpio1, motorSuperior[j][0]);
      digitalWrite(gpio2, motorSuperior[j][1]);
      digitalWrite(gpio3, motorSuperior[j][2]);
      digitalWrite(gpio4, motorSuperior[j][3]);
      delay(10);
    }
  }
  delay(500);

  for (int vueltas = 0; vueltas < 128; vueltas++) {
    for (int j = 3; j >= 0; j--) {
      digitalWrite(gpio1, motorSuperior[j][0]);
      digitalWrite(gpio2, motorSuperior[j][1]);
      digitalWrite(gpio3, motorSuperior[j][2]);
      digitalWrite(gpio4, motorSuperior[j][3]);
      delay(10);
    }
  }
  delay(1000); 
}