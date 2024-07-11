#include "textUtils.h"

string onCenter(string input, int width = 113) { 
   return string((width - input.length()) / 2, ' ') + input;
}

string changeColor(string txt, char color){
   string code = "37"; //by default white
   switch(color){
      case 'R':   code = "31";   break;
      case 'G':   code = "32";   break;
      case 'Y':   code = "33";   break;
      case 'B':   code = "34";   break;
      case 'M':   code = "35";   break;
      case 'C':   code = "36";   break;
      case 'W':   code = "37";   break;
   }

   return ("\x1B[" + code + "m" + txt + "\033[0m");

}

string changeBg(string txt, char color){
   string code = "40"; //by default black
   switch(color){
      case 'R':   code = "41";   break;
      case 'G':   code = "42";   break;
      case 'Y':   code = "43";   break;
      case 'B':   code = "44";   break;
      case 'M':   code = "45";   break;
      case 'C':   code = "46";   break;
      case 'W':   code = "47";   break;
   }

   return ("\033[3;" + code + ";30m" + txt + "\033[0m\t\t");
}

string addSuffix(int num){
   if(num == 1)
      return "st";
   else if(num == 2)
      return "nd";
   else if(num == 3)
      return "rd";
   else 
      return "th";
}
