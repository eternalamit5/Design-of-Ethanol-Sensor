//Declaration of variables

const int x = A0;                  
const int y = A2;    
float value;   
float ct;   
float ci=26.55;  //Internal capacitance has been choosen as 26.55 pF
const int MAX_ADC_VALUE=1023;

        
void setup() {
// initialize the serial communications:
  Serial.begin(9600);
// Set A0 and A2 as Output
   pinMode(x, OUTPUT);
   pinMode(y, OUTPUT);
  
}

void loop() {
  
   pinMode(x, INPUT);  //Set A0 as Input
   digitalWrite(y,HIGH); //Set A2 high
   value=analogRead(x);  //Read the A0 pin
   digitalWrite(y,LOW);  // Set A2 low
   pinMode(x, OUTPUT); //set A0 as output

// Calculate internal capacitance
   //ci=(ct)*((MAX_ADC_VALUE)-(value))/(value);
   
// Calculate test capacitance
   
   ct=(value)*(ci)/((MAX_ADC_VALUE)-(value));  
 /*
 Serial.print("Test Capacitance value =");
 Serial.print(ct);
 Serial.print(" pF  ");
 Serial.println("");
  */
 
  Serial.println(ct);
  
// delay before next reading:
  delay(100);
}