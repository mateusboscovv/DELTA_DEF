#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

//#define D_LDR A1                 //define o botão no pino 10 (MAIS)

int tela = 0, ldr; //variável para controlar a mudança de tela no menu
char lcd_valor_ldr[40];
 
void setup(){ 

  lcd.begin (16,2);                    //inicia o display 16x2
   lcd.clear();                       //limpa todos os caracteres do lcd
   lcd.setCursor(0,0);                //posiciona o cursor no display (caracter, linha)      
   lcd.print(F(" AQUECA OS  "));    
   lcd.setCursor(0,1);                      
   lcd.print(F(" PISTOES...   "));   
 delay (2000);                        
 }
 
void loop(){
  
  // Lembrete
  ldr = analogRead(A1);
 
// === Ações no display LCD === // 
    
   if (tela==0){                          //se a variável tela for igual a MAIS, faça...
     lcd.setCursor(0,0);                    //posiciona o cursor no display (caracter, linha)      
     lcd.print(F("DEBOA MANDA VER"));      //imprime o texto entre aspas 
   
   } else {                          //se a variável tela for igual a MAIS, faça...
     lcd.setCursor(0,0);                    //posiciona o cursor no display (caracter, linha)      
     lcd.print(F("     COLISAO    "));      //imprime o texto entre aspas 
   }
  
  
   lcd.setCursor(0,1);                    //posiciona o cursor no display (caracter, linha)      
   sprintf (lcd_valor_ldr, "ADC LDR: = %d    ", ldr); // usa função sprintf para converter o valor inteiro em ascii e concatenar ao texto "LDR: = ",pois não é a mesma biblioteca de escrite em PC
  lcd.print(lcd_valor_ldr);
  
/////////////////////////////////////////////////

// === Ações do Botão ENTER === //   ////////////

  if (ldr <= 55 ) {
    tela = 1;            
      
  } else {
    tela = 0;    
  }
  
 delay(250);
  
  
  
   if (tela==1){                          //se a variável tela for igual a MAIS, faça...
   lcd.setCursor(0,0);                    //posiciona o cursor no display (caracter, linha)      
   lcd.print(F("   << MENU >>   "));      //imprime o texto entre aspas 
   lcd.setCursor(0,1);                    //posiciona o cursor no display (caracter, linha)      
   lcd.print(F(">Primeira Opcao "));      //imprime o texto entre aspas 
   }
   else if (tela==2){                            
   lcd.setCursor(0,0);                     
   lcd.print(F("   << MENU >>   "));      
   lcd.setCursor(0,1);                     
   lcd.print(F(">Segunda Opcao  "));     
   }
   else if (tela==3){                            
   lcd.setCursor(0,0);                     
   lcd.print(F("   << MENU >>   "));      
   lcd.setCursor(0,1);                     
   lcd.print(F(">Terceira Opcao  "));     
   }
   else if (tela==10){                            
   lcd.setCursor(0,0);                     
   lcd.print(F(" :: PRIMEIRO :: "));      
   lcd.setCursor(0,1);                     
   lcd.print(F("  ete fmc      "));     
   }
   else if (tela==20){  
   lcd.setCursor(0,0);                           
   lcd.print(F(" :: SEGUNDO ::  "));      
   lcd.setCursor(0,1);                     
   lcd.print(F("   projete      "));     
   }
   else if (tela==30){
   lcd.setCursor(0,0);                              
   lcd.print(F(" :: TERCEIRO :: "));      
   lcd.setCursor(0,1);                     
   lcd.print(F("    sala 13      "));     
   }
   
/////////////////////////////////////////////////

// === Ações do Botão MAIS === //    ////////////
  L_botao_MAIS = digitalRead(botao_MAIS);
  if (!L_botao_MAIS && LA_botao_MAIS) {
                if (tela==1)tela=2; 
       else if (tela==2)tela=3;
       else if (tela==3)tela=1;    
       delay(30);}                         
  LA_botao_MAIS = L_botao_MAIS; 


/////////////////////////////////////////////////

// === Ações do Botão MENOS === //   ////////////
  L_botao_MENOS = digitalRead(botao_MENOS);
  if (!L_botao_MENOS && LA_botao_MENOS) {
       if (tela==1)tela=3; 
       else if (tela==2)tela=1;
       else if (tela==3)tela=2;  
       delay(30);}                         
  LA_botao_MENOS = L_botao_MENOS;

     
/////////////////////////////////////////////////

// === Ações do Botão ENTER === //   ////////////
  L_botao_ENTER = digitalRead(botao_ENTER);
  if (!L_botao_ENTER && LA_botao_ENTER) {
            if (tela==1)tela=10; 
       else if (tela==2)tela=20;
       else if (tela==3)tela=30;
       else if (tela==10)tela=1;
       else if (tela==20)tela=2;
       else if (tela==30)tela=3;         
       delay(30);}                         
  LA_botao_ENTER = L_botao_ENTER;
  

}
