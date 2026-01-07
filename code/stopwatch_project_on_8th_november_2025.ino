int led[] = {2, 3, 4, 5, 6, 7, 8};
int first_digit = 12;
int second_digit = 11;
int third_digit = 10;
int fourth_digit = 9;

int button1_pin = A0;
int button2_pin = A1;
int button3_pin = A2;
int button4_pin = A3;

int button1;
int button2;
int button3;
int button4;

int zero[] = {1, 1, 1, 1, 1, 1, 0};
int one[] = {0, 1, 1, 0, 0, 0, 0};
int two[] = {1, 1, 0, 1, 1, 0, 1};
int three[] ={1, 1, 1, 1, 0, 0, 1};
int four[] = {0, 1, 1, 0, 0, 1, 1};
int five[] = {1, 0, 1, 1, 0, 1, 1};
int six[] = {1, 0, 1, 1, 1, 1, 1};
int seven[] = {1, 1, 1, 0, 0, 0, 0};
int eight[] = {1, 1, 1, 1, 1, 1, 1};
int nine[] = {1, 1, 1, 0, 0, 1, 1};

int first_led = 0;
int second_led = 0;
int third_led = 0;
int fourth_led = 0;

int seconds_timer = 0;
int minute_timer = 0;
int switchstate = 0;


void display_led(int display, int n){
  digitalWrite(display, LOW);


  switch(n){
    case 0:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], zero[i]);
    }
    break;

 case 1:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], one[i]);
    }
    break;

    case 2:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], two[i]);
    }
    break;

    case 3:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], three[i]);
    }
    break;

     case 4:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], four[i]);
    }
    break;


     case 5:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], five[i]);
    }
    break;


     case 6:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], six[i]);
    }
    break;

     case 7:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], seven[i]);
    }
    break;

     case 8:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], eight[i]);
    }
    break;

     case 9:
    for(int i = 0; i < 8; i++){
      digitalWrite(led[i], nine[i]);
    }
    break;
  }
}


void seconds_counter(int first_led, int second_led, int third_led, int fourth_led){
  for(int i = 0; i < 100; i++){
delay(2);
display_led(first_digit, first_led);
delay(2);
digitalWrite(first_digit, HIGH);
display_led(second_digit, second_led);
delay(2);
digitalWrite(second_digit, HIGH);
display_led(third_digit, third_led);
delay(2);
digitalWrite(third_digit, HIGH);
display_led(fourth_digit, fourth_led);
delay(2);
digitalWrite(fourth_digit, HIGH);
  }
}


void timer(int n){

  switch(n){
    case 0:
    if(button1 == 1){
      seconds_timer = seconds_timer + 1;
    }
    else if (button2 == 1){
      seconds_timer = seconds_timer - 1;
    }

    if(seconds_timer >= 60 || seconds_timer < 0){
      seconds_timer = 0;
    }

    fourth_led = int(seconds_timer % 10);
    third_led = int(seconds_timer / 10) % 10;
    seconds_counter(first_led, second_led, third_led, fourth_led);
    break;

    case 1:
    if(button1 == 1){
      minute_timer += 1;
    }
    else if(button2 == 1){
      minute_timer = minute_timer - 1;
    }
    if(minute_timer >= 60 || minute_timer < 0){
      minute_timer = 0;
    }
    second_led = int(minute_timer % 10);
    first_led = int(minute_timer / 10) % 10;
    seconds_counter(first_led, second_led, third_led, fourth_led);
    break;
  }
}

void stopwatch(int n, int k){
  while(n <= 59){
    third_led = int(n / 10) % 10;
    fourth_led = n % 10;
    seconds_counter(first_led, second_led, third_led, fourth_led);
    n = n - 1;
    if(n < 0){
      k = k - 1;
      first_led = int(k / 10) % 10;
      second_led = k % 10;
      seconds_counter(first_led, second_led, third_led, fourth_led);
      if(k < 0){
        k = 0;
      }
      n = 59;
    }
  }
}
void setup() {
  // put your setup code here, to run once:
for(int i = 2; i < 13; i++){
  pinMode(i, OUTPUT);
}

pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(button3, INPUT);
pinMode(button4, INPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
button1 = digitalRead(button1_pin);
button2 = digitalRead(button2_pin);
button3 = digitalRead(button3_pin);
button4 = digitalRead(button4_pin);

if(button3 == 1){
  if(switchstate == 0){
    switchstate = 1;
  }
  else if(switchstate == 1){
    switchstate = 0;
  }
}

timer(switchstate);


if(button4 == 1){
  stopwatch(seconds_timer, minute_timer);
}


}
