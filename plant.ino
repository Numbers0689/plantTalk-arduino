const short LED = 13;
const short THRESHOLD = 550;
const short INTERVAL = 10000;
const short SERIAL_BAUD_RATE = 9600;

bool needsWater()
{
    short a = analogRead(A0);
    Serial.print(a);
    Serial.print(":\t");

    if(a < THRESHOLD)
        return true;
    else
        return false;
}

void indicateDry(){
    digitalWrite(LED, HIGH);
    Serial.println("Feed Me!");
}

void indicateMoist(){
    digitalWrite(LED, LOW);
    Serial.println("Thank You");
}

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);
    pinMode(LED, OUTPUT);
}

void loop(){
    if (needsWater())
    {
        indicateDry();
    }
    else{
        indicateMoist();
    }

    delay(INTERVAL);
    
}