#include<iostream>
#include<math.h>
using namespace std;


int potencia(int col);
int *Filas_patrones(int n);
int *verificacion();

int main()
{
    //PATRONES PARA CONSOLA:
   
   
    int *arreglo_ent;
    arreglo_ent=verificacion();
    for(int i=0;i<8;i++){
        cout<<arreglo_ent[i]<<endl;
    }
    arreglo_ent=Filas_patrones(2);
    for(int i=0;i<8;i++){
        cout<<arreglo_ent[i]<<endl;
    }

    delete [] arreglo_ent;
    /*
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
    */

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