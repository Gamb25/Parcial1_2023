#include<iostream>
#include<math.h>
using namespace std;


int potencia(int col);
int *Filas_patrones(int n);
int *verificacion();
void personalizado();

int main()
{
    //PATRONES PARA CONSOLA:
   
   
   /* int *arreglo_ent;
    arreglo_ent=verificacion();
    for(int i=0;i<8;i++){
        cout<<arreglo_ent[i]<<endl;
    }
    arreglo_ent=Filas_patrones(2);
    for(int i=0;i<8;i++){
        cout<<arreglo_ent[i]<<endl;
    }

    delete [] arreglo_ent;*/
    //personalizado();
    
    int contador_3=0, arreglo_2[8]={0}, numerobinario=0;
    //Patron 1:
    for(int filas=0;filas<4;filas++){
        
        for(int columnas=0;columnas<4;columnas++){
            if(columnas<3-filas){
                
              	cout<<'.';
               
            }
            else{ 
                numerobinario=numerobinario+pow(2,columnas);
              	cout<<'*';
            }
        
        }
        for(int columnas=0;columnas<4;columnas++){
            if(columnas<=filas){

                numerobinario=numerobinario+pow(2,columnas+4);
              	cout<<'*';
            }
            else{ 
                
                cout<<'.';
            }
            
        }
      	cout<<'\n';
        arreglo_2[contador_3]=numerobinario;
        numerobinario=0;
        contador_3++;
    }
    for(int filas=0;filas<4;filas++){
        

        for(int columnas=0;columnas<4;columnas++){
            if(columnas>=filas){
                numerobinario=numerobinario+pow(2,columnas);
              	cout<<'*';
            }
            else {
              	cout<<'.';
            }
        }    
        for(int columnas=0;columnas<4;columnas++){
            if(columnas<4-filas){

                numerobinario=numerobinario+pow(2,columnas+4);
              	cout<<'*';
            }
            else {

              	cout<<'.';
            }
        }  
      	cout<<'\n';
        arreglo_2[contador_3]=numerobinario;
        numerobinario=0;
        contador_3++;
    }

   
    ///Patron2
    for(int filas=0;filas<4;filas++){
        
    for(int columnas=0;columnas<4;columnas++){
            if(columnas==filas){
                cout<<'*';
            }
            else cout<<'-';
        }
        for(int columnas=0;columnas<4;columnas++){
            if(columnas==3-filas){
                cout<<'*';
            }
            else cout<<'-';
        }  
        cout<<endl;
        
    }
    for(int filas=0;filas<4;filas++){
        

        for(int columnas=0;columnas<4;columnas++){
            if(columnas==3-filas){
                cout<<'*';
            }
            else cout<<'-';
        }    
        for(int columnas=0;columnas<4;columnas++){
            if(columnas==filas){
                cout<<'*';
            }
            else cout<<'-';
        }  


        cout<<endl;
        
    }
    //patron Patron 3:
    numerobinario=0;
    contador_3=0;
    for(int columnas=0;columnas<8;columnas++){
        if(columnas!=5 && columnas!=2){
            numerobinario+=potencia(columnas);
        }
        
        else cout<<'-';
    }
    for(int posiciones=0;posiciones<8;posiciones+=4){
        arreglo_2[posiciones]=numerobinario;
        arreglo_2[posiciones+1]=numerobinario;
    }
    numerobinario-=37;
        for(int posiciones=2;posiciones<8;posiciones+=4){
        arreglo_2[posiciones]=numerobinario;
        arreglo_2[posiciones+1]=numerobinario;
    }
    cout<<endl;
    
    //patron Patron 4:
    numerobinario=0;
    contador_3=0;
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
        arreglo_2[contador_3]=numerobinario;
        contador_3++;
        numerobinario=0;
    }
    for(int filas=0;filas<4;filas++){
        for(int columnas=0;columnas<4;columnas++){
            if(columnas<=3-filas){
                numerobinario=numerobinario+potencia(columnas);
            }
        }
        for(int columnas=0;columnas<4;columnas++){
            if(columnas>3-filas){
                numerobinario=numerobinario+potencia(columnas+4);
            }
        }
        arreglo_2[contador_3]=numerobinario;
        contador_3++;
        numerobinario=0;
    }
    //patron escalera/Patron5:

    numerobinario=0;
    contador_3=0;
    for(int filas=0;filas<8;filas++){
        for(int columnas=0;columnas<8;columnas++){
            if(columnas<1+filas){
                cout<<'*';
                numerobinario=numerobinario+potencia(columnas);
            }
        }
        cout<<endl;
        arreglo_2[contador_3]=numerobinario;
        contador_3++;
        numerobinario=0;
    }

    cout<<potencia(3);

 return 0;
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
    else if(n==3){

    }
    else if(n==4){

    }
    return arreglo;  
}
//Funcion verificadora de leds.
int *verificacion(){
    int*temp;
    temp=Filas_patrones(0);
    return temp;
}
//Funcion patron al azar
void personalizado(){
    int arreglo[8], contador=0,num,numerobinario=0;
    for(int filas=0;filas<8;filas++){
        for(int leds=0;leds<8;leds++){
            cout<<"Para encender un led se te daran las coordenadas del mismo, para encender escribe 1 y para mantener apagado escribe \n";
            cout<<"Estamos en la "<<filas<<" led "<<leds<<"asignale un valor como encendidio o apagado: ";
            cin>>num;
            if(num==1)numerobinario+=potencia(leds);
        }

        arreglo[contador]=numerobinario;
        contador++;
        numerobinario=0;
    }

    cout<<"terminado";
}