// C++ code
//
int latchPin=12;
int clockPin=11;
int dataPin=10;



int potencia(int col); 
int *Filas_patrones(int n);
void verificacion();
void imagen();
void mostrar(int*, int );
void mostrar_tpatrones();
void Publik();




void setup()
{
	Serial.begin(9600);

  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
//Verificacion:
   	verificacion();
//Funcion Publik
  Publik();



}
//Funcion potencia:
int potencia(int col){
    int almacenador=1;
    if(col==0){ 
        return 1;
        }
    else{
        for(int i=1;i<=col;i++){
            almacenador=2*almacenador;
        }
        return almacenador;
    }
}
//Funcion generadora de patrones:
int *Filas_patrones(int n){
    int contador_2=0,contador_3=0,numerobinario=0;
    int *arreglo=new int[8];
    
    //Patron de prueba:
    if(n==0)
    {
        for(int i=0;i<8;i++){
            arreglo[i]=255;
        }
    }
    //Primer patron:

    else if(n==1){
        for(int filas=0;filas<4;filas++){
            for(int columnas=0;columnas<4;columnas++){
                if(columnas<3-filas){

                }
                else{
                    numerobinario=numerobinario+potencia(columnas);
                }
            }
            
            for(int columnas=0;columnas<4;columnas++){
                if(columnas<=filas){
                numerobinario=numerobinario+potencia(columnas+4);
                }
            }
            arreglo[contador_3]=numerobinario;
            numerobinario=0;
            contador_3++;
        }
        for(int filas=0;filas<4;filas++){
            for(int columnas=0;columnas<4;columnas++){
                if(columnas>=filas){
                    numerobinario=numerobinario+potencia(columnas);
                }
            }
            for(int columnas=0;columnas<4;columnas++){
                if(columnas<4-filas){
                    numerobinario=numerobinario+potencia(columnas+4);
                }
            }
            arreglo[contador_3]=numerobinario;
            numerobinario=0;
            contador_3++;
        }

    }
    //Patron 2:
    else if(n==2){
        for(int filas=0;filas<4;filas++){
            for(int columnas=0;columnas<4;columnas++){
                if(columnas==filas){
                    numerobinario=numerobinario+potencia(columnas);
                    
                }
            }
            for(int columnas=0;columnas<4;columnas++){
                if(columnas==3-filas){
                    numerobinario=numerobinario+potencia(columnas+4);
                }
            }  
            arreglo[contador_3]=numerobinario;
            numerobinario=0;
            contador_3++;
            
        }
        for(int filas=0;filas<4;filas++){
            for(int columnas=0;columnas<4;columnas++){
                if(columnas==3-filas){
                    numerobinario=numerobinario+potencia(columnas);
                }
            }    
            for(int columnas=0;columnas<4;columnas++){
                if(columnas==filas){
                    numerobinario=numerobinario+potencia(columnas+4);
                }
            }  
            arreglo[contador_3]=numerobinario;
            numerobinario=0;
            contador_3++;
            
        }
    }
  //Patron 3:
    else if(n==3){
    for(int columnas=0;columnas<8;columnas++){
        if(columnas!=5 && columnas!=2){
            numerobinario+=potencia(columnas);
        }
    }
    for(int posiciones=0;posiciones<8;posiciones+=4){
        arreglo[posiciones]=numerobinario;
        arreglo[posiciones+1]=numerobinario;
    }
    numerobinario=numerobinario-37;
      
    for(int posiciones=2;posiciones<8;posiciones+=4){
        arreglo[posiciones]=numerobinario;
        arreglo[posiciones+1]=numerobinario;
    }

    }
  //Patron 4:
    else if(n==4){
    for(int filas=0;filas<4;filas++){
        for(int columnas=0;columnas<4;columnas++){
            if(columnas>=filas){
                numerobinario=numerobinario+potencia(columnas);
            }
        }
        for(int columnas=0;columnas<4;columnas++){
            if(columnas<filas){
                numerobinario=numerobinario+potencia(columnas+4);
            }
        }
        arreglo[contador_3]=numerobinario;
        contador_3++;
        numerobinario=0;
    }
    for(int filas=0;filas<4;filas++){
        for(int columnas=0;columnas<4;columnas++){
            if(columnas>=3-filas){
                numerobinario=numerobinario+potencia(columnas);
            }
        }
        for(int columnas=0;columnas<4;columnas++){
            if(columnas<3-filas){
                numerobinario=numerobinario+potencia(columnas+4);
            }
        }
        arreglo[contador_3]=numerobinario;
        contador_3++;
        numerobinario=0;
    }

    }
  	else if (n==5){
      for(int filas=0;filas<8;filas++){
        for(int columnas=0;columnas<8;columnas++){
            if(columnas<1+filas){
                numerobinario=numerobinario+potencia(columnas);
            }
        }
        arreglo[contador_3]=numerobinario;
        contador_3++;
        numerobinario=0;
    }
  	}
    return arreglo;  
}
//Funcion verificadora de leds.
void verificacion(){
    int*temp;
  	String notificacion="Verificacion automatica del funcionamiento de los leds...\n";
  	
    temp=Filas_patrones(0);
  	Serial.print(notificacion);
  	mostrar(temp,0);
  	delete[] temp;
  	
}
//Funcion que enciende los leds:
void mostrar(int*arreglo, int n){
  	int dt=4000;
  	if(n>0) dt=n;
	digitalWrite(latchPin, LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[0]);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[1]);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[2]);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[3]);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[4]);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[5]);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[6]);
    shiftOut(dataPin,clockPin,MSBFIRST,arreglo[7]);
  	digitalWrite(latchPin,HIGH);
   	delay(dt);
  
  	digitalWrite(latchPin,LOW);
   	shiftOut(dataPin,clockPin,MSBFIRST,0);
    shiftOut(dataPin,clockPin,MSBFIRST,0);
    shiftOut(dataPin,clockPin,MSBFIRST,0);
    shiftOut(dataPin,clockPin,MSBFIRST,0);
    shiftOut(dataPin,clockPin,MSBFIRST,0);
    shiftOut(dataPin,clockPin,MSBFIRST,0);
    shiftOut(dataPin,clockPin,MSBFIRST,0);
  	shiftOut(dataPin,clockPin,MSBFIRST,0);
  	digitalWrite(latchPin,HIGH);


 

 	delay(dt);
  	
  
}
//Preguntador a usuarios:
void imagen(){
    	int patron,n,*arreglo_2;
  		String pregunta="Que deseas imprimir: \nEscribe 1 para Patron 1: \nEscribe 2 para Patron 2: \nEscribe 3 para Patron 3: \nEscribe 4 para Patron 4: \n";
    	String pregunta_2="\nCuanto tiempo en segundos entre encendido y apagado: \n";
	
  		Serial.print(pregunta);
  		while(Serial.available()==0){
    	}
  		patron=Serial.parseInt();
    
  		arreglo_2=Filas_patrones(patron);
    
    	Serial.print(pregunta_2);
  		while(Serial.available()==0){
    	}
  		n=Serial.parseInt();
      	n*=1000;
  		arreglo_2=Filas_patrones(patron);
    
  		mostrar(arreglo_2,n);
  		delete[]arreglo_2;
  	
  	
}
//Mostrar todos los patrones:
void mostrar_tpatrones(){
int n_2,*arreglo_2;
    	String pregunta="\nCuanto tiempo en segundos entre encendido y apagado: \n";
    	String pregunta_2="Se van a mostrar todos los patrones...\n";
      	Serial.print(pregunta);
      	
    
  		while(Serial.available()==0){
    	}
  		n_2=Serial.parseInt();
      	n_2*=1000;
    	Serial.print(pregunta_2);
  		for(int i=1;i<5;i++){
      	arreglo_2=Filas_patrones(i);
        	 mostrar(arreglo_2,n_2);
     	}
     	delete[]arreglo_2;
  	
}
//Funcion Publik:
void Publik(){
  	int n_3;
  	String pregunta_3="Escribe 1 para verificar.\nEscribe 2 para mostrar un patron de tu eleccion.\nEscribe 3 para mostrar todos los patrones.\n";
  	Serial.print(pregunta_3);
    while(Serial.available()==0){
    }
   	n_3=Serial.parseInt();
 	if(n_3==1){
      int n,n_2,*arreglo_2;
    	String pregunta="\nCuanto tiempo en segundos entre encendido y apagado: \n";
  		String pregunta_2="Cuantos patrones?\n";
      	Serial.print(pregunta);
      	while(Serial.available()==0){
      	}
      	n=Serial.parseInt();
      	n*=1000;
      	Serial.print(pregunta_2);
      	while(Serial.available()==0){
      	}
      	n_2=Serial.parseInt();
      	for(int i=1;i<=n_2;i++){
          	arreglo_2=Filas_patrones(i);
            mostrar(arreglo_2,n);
      	}
      	delete[]arreglo_2;
  	}
  	if(n_3==2){
		imagen();
  
  	}
  	if(n_3==3){
		mostrar_tpatrones();
  	}
}

