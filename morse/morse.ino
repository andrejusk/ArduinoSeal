String navySeal = "What the fuck did you just fucking say about me, you little bitch? I’ll have you know I graduated top of my class in the Navy Seals, and I’ve been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills.  I am trained in gorilla warfare and I’m the top sniper in the entire US armed forces.  You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker.";

char morseLettersLowercase[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char morseLettersUppercase[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
String morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", ""};

int delayTime = 100;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  /* Initial 2s pause */
  delay(20 * delayTime);
  
  /* For every character in the navy seal copypasta... */
  for (int textIterator = 0; textIterator < navySeal.length(); textIterator++) {
    /* ...find corresponding character in morse alphabet */
    int location = 27; //Defaults to ignoring character

    /* Handles space bar */
    if (navySeal.charAt(textIterator) == ' ') {
      output(morseCode[26]);
      continue;
    }
    
    /* For every known morse code character... */
    for (int characterIterator = 0; characterIterator < sizeof(morseLettersUppercase); characterIterator++) {
      /* ...checks for both uppercase and lowercase version */
      if (navySeal.charAt(textIterator) == morseLettersUppercase[characterIterator] || navySeal.charAt(textIterator) == morseLettersLowercase[characterIterator]) {
        /* Saves location in case of match */
        location = characterIterator;
        break;
      }
    }
    
    /* Outputs morse version of the letter */
    output(morseCode[location]);
    delay(4 * delayTime);
  }

}

void output(String outputText) {
  /* For every simbol in the morse code... */
  for (int morseIterator = 0; morseIterator < outputText.length(); morseIterator++) {
    /* ...do the correct output */
    switch (outputText.charAt(morseIterator)) {
      case '.': shortBlink(); break;
      case '-': longBlink(); break;
      case ' ': pause(); break;
      default: break;
    }
    delay(delayTime);
  }
}

/** Outputs '.' with a short blink **/
void shortBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delayTime);
  digitalWrite(LED_BUILTIN, LOW);
}

/** Outputs '-' with a long blink **/
void longBlink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(4 * delayTime);
  digitalWrite(LED_BUILTIN, LOW);
}

/** Outputs ' ' with a pause **/
void pause() {
  delay(4 * delayTime);
}

