String navySeal = "WHAT THE FUCK DID YOU JUST FUCKING SAY ABOUT ME   YOU LITTLE BITCH    ILL HAVE YOU KNOW I GRADUATED TOP OF MY CLASS IN THE NAVY SEALS   AND IVE BEEN INVOLVED IN NUMEROUS SECRET RAIDS ON AL-QUAEDA   AND I HAVE OVER 300 CONFIRMED KILLS    I AM TRAINED IN GORILLA WARFARE AND IM THE TOP SNIPER IN THE ENTIRE US ARMED FORCES    YOU ARE NOTHING TO ME BUT JUST ANOTHER TARGET   YOU GODDAMN IDIOT    I WILL SHIT FURY ALL OVER YOU AND YOU WILL DROWN IN IT    YOURE FUCKING DEAD   KIDDO   ";
int delayTime = 100;

char morseLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
String morseCode[] = {".-","-...","-.-.", "-..",".","..-.", "--.", "....","..", ".---", "-.-",".-..","--","-.","---",".--.", "--.-", ".-.", "...", "-","..-","...-", ".--","-..-", "-.--", "--..", " "};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //initial 5s pause
  delay(50 * delayTime);
  int location;

  //for every character in the navy seal copypasta
  for (int textIterator = 0; textIterator < navySeal.length(); textIterator++) {
    //find character in morse alphabet
    location = 26; //defaults to empty space
    for (int characterIterator = 0; characterIterator < sizeof(morseLetters); characterIterator++) {
      if (navySeal.charAt(textIterator) == morseLetters[characterIterator]) {
        location = characterIterator; //sets if matches
        break;
      }
    }
    //outputs morse version of letter
    output(morseCode[location]);
    delay(4 * delayTime);
  }
  
  

}

void output(String outputText) {
  for(int morseIterator = 0; morseIterator < outputText.length(); morseIterator++) {
    switch(outputText.charAt(morseIterator)) {
      case '.': shortBlink(); break;
      case '-': longBlink(); break;
      case ' ': pause(); break;
      default: break;
    }
    delay(delayTime);
  }
}

/** outputs '.' **/
void shortBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delayTime);
  digitalWrite(LED_BUILTIN, LOW);
}

/** outputs '-' **/
void longBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(4 * delayTime);
  digitalWrite(LED_BUILTIN, LOW);
}

/** outputs ' ' **/
void pause() {
  delay(2 * delayTime);
}

