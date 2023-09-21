#include<iostream>
#include<math.h>
using namespace std;




int potencia(int col);
int main()
{

    int contador_2=0,contador_3=0,numerobinario=0, arreglo_2[8]={0};
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