#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;

int flujo=999;


void Carga(){
	for (int i=0; i<=100; i++){
			system("cls");
		cout<<"                               1--agregar otro"<<endl;
		cout<<"                               2--para salir"<<endl;
		cin>>flujo;
		
		switch(flujo){
			
			case 1:continue; break;
			case 2: break;
			default: cout<<"                 valor incorrecto"<<endl;
		}
	
	}	
}

void addtoMenu(){
	
	while(flujo==2){
		system("cls");
		ofstream archivo;
		archivo.open("Menucomida.txt",ios::out | ios::app);
		char nombrePlato[20];
		int precioPlato, idPlato;
	
		cout<<"                                   Introduce los datos solicitados del menu."<<endl;
	
		if(archivo.fail()){
		cout<<"                               No se pudo crear el archivo."<<endl;
		//exit(1);
		}
	
		cout<<"                                  Id del plato"<<endl;
		cout<<"                                 "; cin>>idPlato;
		
		cout<<"                                  Nombre del plato"<<endl;
		
	
		cout<<"                                  Precio del plato"<<endl;
		cout<<"                                  "; cin>>precioPlato; gets(nombrePlato);
		

	
	
		archivo<<idPlato<<" "<<nombrePlato<<" "<<precioPlato<<endl;
		archivo.close();
	
		system("cls");
	
		cout<<"El plato fue añadido con exito."<<endl;

	
	
	
		system("pause");
	}

}


int autoIdclient(){
	string nomClient, apellClient, telClient;
	int idClient;	
	
	//cout<<"test";
	
	ifstream archivo;
	archivo.open("cliente.txt",ios::in);
	

	if(archivo.fail()){
		cout<<"No se encontro dato para filtral."<<endl;
		//exit(1);
	}
	
    
	while(!archivo.eof()){
		archivo>>idClient;
        archivo>>nomClient;
        archivo>>apellClient;
        archivo>>telClient;
        
        //cout<<idClient<<" "<<nomClient<<" "<<apellClient<<telClient<<endl;
	}
	
	idClient=idClient+1;
	//cout<<idClient;

	return idClient;
}




void agregarCliente(){
	system("cls");
	
	int idClient=autoIdclient();
	
	
	ofstream archivo;
	archivo.open("cliente.txt",ios::out | ios::app);
	string nombreClient, apellidoClient, contactoClient;
	
	cout<<"                                   introduce los datos del usuario."<<endl;
	
	if(archivo.fail()){
		cout<<"                               No se pudo crear el archivo."<<endl;
		exit(1);
	}
	
	
	cout<<"                                  Nombre de cliente"<<endl;
	cout<<"                                 "; cin>>nombreClient;
	
	cout<<"                                  Apellido "<<endl;
	cout<<"                                 "; cin>>apellidoClient;
	
	cout<<"                                  Numero telefonico  "<<endl;
	cout<<"                                  "; cin>>contactoClient;
	
	archivo<<idClient<<" "<<nombreClient<<" "<<apellidoClient<<" "<<contactoClient<<endl;
	archivo.close();
	
	system("cls");
	cout<<"Cliente guardado exitosamente"<<endl;
	system("pause");
	
	
}






string filtrarCliente(){
    string nombreClient, apellidoClient, contactoClient, idClient, filtro, filtro2;
	ifstream archivo;
	archivo.open("cliente.txt",ios::in);
	cout<<"									Introduce id, telefono, nombre o apellido."<<endl;
    cout<< "                               ";  cin>>filtro;

	if(archivo.fail()){
		cout<<"No se contro dato para filtral."<<endl;
		//exit(1);
	}
    
    archivo>>idClient;
	while(!archivo.eof()){
		
		archivo>>nombreClient;
        archivo>>apellidoClient;
        archivo>>contactoClient;

         if(filtro==nombreClient || filtro==apellidoClient || filtro==contactoClient){
		  	
            cout<<"				"<<idClient<<nombreClient<<" "<<apellidoClient<<" "<<contactoClient<<endl;
            
            archivo>>nombreClient;
       }
	}

	archivo.close();
	system("pause");
	
	
	return  idClient+" "+nombreClient;
}






void gestionMenu(){
	
    while(flujo!=101){
        system("cls");
	    cout<<"                                     Gestion de Menu"<<endl;
	    cout<<"                                  1--Ver menu"<<endl;
        cout<<"                                  2--Agregar Plato"<<endl;
        cout<<"                                  3--Quitar plato"<<endl;
        cout<<"                                  4--Modificar plato"<<endl;
        cout<<"                                  5--Menu principal"<<endl;
        cout<<"                                  6--Salir"<<endl;
        cout<<"                                     valor:";cin>>flujo;
      
        switch(flujo){
            case 1:break;
        
            case 2: addtoMenu(); 
			break;
          
            case 3:break;
          
            case 4:break;
          
            case 5: flujo=101; break;

            case 6: flujo=100; break; 

            default:
            cout<<"                               Valor Incorrecto"<<endl;   
        }
        if(flujo==100) break;
    }    
}






int numOrden(){
	string mesa;
	int numOrden;	
	
	//cout<<"test";
	
	ifstream archivo;
	archivo.open("Ordenes.txt",ios::in);
	

	if(archivo.fail()){
		cout<<"No se encontro dato para filtral."<<endl;
		//exit(1);
	}
	
    
	while(!archivo.eof()){
        archivo>>numOrden;
        archivo>>mesa;
        
        cout<<numOrden<<" "<<mesa<<endl;
	}
	
	numOrden=numOrden+1;
	cout<<numOrden;

	return numOrden;
}


string getClient(int filtro){
	string nomClient, apellClient, telClient, nameBack;
	int idClient;
		
	
	
	//cout<<"test";
	
	ifstream archivo;
	archivo.open("cliente.txt",ios::in);
	

	if(archivo.fail()){
		cout<<"No se encontro dato para filtral."<<endl;
		//exit(1);
	}
	
    
	while(!archivo.eof()){
		archivo>>idClient;
        archivo>>nomClient;
        archivo>>apellClient;
        archivo>>telClient;
        
        if(idClient==filtro){
        	nameBack=nomClient;
		}
        
        //cout<<idClient<<" "<<nomClient<<" "<<apellClient<<telClient<<endl;
	}
	

	return nameBack;
	
}




string numeroMesa(int mesa){ 
	string numeroMesa;
	
	switch(mesa){
		case 1: numeroMesa="mesa1"; break;
		case 2: numeroMesa="mesa2"; break;
		case 3: numeroMesa="mesa3"; break;
		case 4: numeroMesa="mesa4"; break;
		case 5: numeroMesa="mesa5"; break;
		case 6: numeroMesa="mesa6"; break;
		case 7: numeroMesa="mesa7"; break;
		case 8: numeroMesa="mesa8"; break;
		case 9: numeroMesa="mesa9"; break;
		case 10: numeroMesa="mesa10"; break;
		case 11: numeroMesa="mesa11"; break;
		case 12: numeroMesa="mesa12"; break;
		case 13: numeroMesa="mesa13"; break;
		case 14: numeroMesa="mesa14"; break;
		case 15: numeroMesa="mesa15"; break;
		case 16: numeroMesa="mesa16"; break;
		case 17: numeroMesa="mesa17"; break;
		default:  return 0; //cout<<"                    No tenemos ese numero de mesa habilitado actualmente"endl;
	}
	
	return numeroMesa;
}





void ponerOrden(){
		system("cls");
	
	ofstream archivo;
	archivo.open("Ordenes.txt",ios::out | ios::app);
	int mesa, numPedido, idClient;
	string valorMesa, nomClient; 
	
	//getPedido();
	//getHorapedido();
	//getIdClient();
	
	
	cout<<"                                   En que mesa pondras la orden del 1 al 17"<<endl;
	cout<<"                                   ";cin>>mesa;
	valorMesa=numeroMesa(mesa);//para colocar orden en una mesa
	
	cout<<"                                   Introduce el id Del Cliente"<<endl;
	cout<<"                                   ";cin>>idClient;
	nomClient=getClient(idClient);//para colocar el nombre y el id del cliente
	
	cout<<"                                   coloca el pedido solicitado"<<endl;
	
	
	
	numPedido=numOrden();//para conseguir el numero de pedido
	

	
	if(archivo.fail()){
		cout<<"                               No se pudo crear el archivo."<<endl;
		exit(1);
	}
	

	
	archivo<<numPedido<<" "<<valorMesa<<" "<<idClient<<" "<< nomClient<<"\n";
	
 system("pause");
	
}



void Cliente(){

while(flujo!=101){
        system("cls");
	    cout<<"                                 Menu Cliente"<<endl;
	    cout<<"                                  1--Agregar clientes"<<endl;
        cout<<"                                  2--Actualizar clientes"<<endl;
        cout<<"                                  3--Filtrar clientes"<<endl;
        cout<<"                                  4--Eliminar"<<endl;
        cout<<"                                  5--Menu principal"<<endl;
        cout<<"                                  6--Salir"<<endl;
        cout<<"                                     valor:";cin>>flujo;
      
        switch(flujo){
            case 1: agregarCliente(); break;
        
            case 2:break;
          
            case 3: filtrarCliente(); break;
          
            case 4:break;
          
            case 5: flujo=101; break;

            case 6: flujo=100; break; 

            default:
            cout<<"                               Valor Incorrecto"<<endl;   
        }
        if(flujo==100) break;
    }    
}





void Pedido(){
    while(flujo!=101){
    	system("cls");
		cout<<"                                     Pedidos"<<endl;
		cout<<"                                  1--Poner Orden"<<endl;
		cout<<"                                  2--IDclietne"<<endl;
		cout<<"                                  3--Menú de comida"<<endl;
		cout<<"                                  4--Factura."<<endl;
		cout<<"                                  5--Filtrar pedido"<<endl;
		cout<<"                                  6--Actualizar pedido"<<endl;
		cout<<"                                  7--Eliminar pedido"<<endl;
		cout<<"                                  8--Volver al menu principal"<<endl;
		cout<<"                                  9--Menu principal"<<endl;
		cout<<"                                  9--Salir"<<endl;
		cout<<"                                     valor:";cin>>flujo;
    
    	switch(flujo){
        	case 1: ponerOrden(); break;
          
        	case 2:break;
        
        	case 3:break;
          
        	case 4:break;
          
        	case 5:break;
        
        	case 6:break;
        
        	case 7:break;
        
        	case 8: flujo=101 ;break;

        	case 9: flujo= 100;break;
        
        	default:
        	cout<<"                              Valor Incorrecto"<<endl;
    	}

        if(flujo==100) break;

    }  
}


void Administrador(){	
    
    
    while(flujo!=100){
		system("cls");
		cout<<"          **    **                                                                          "<<endl;
        cout<<"*************  *****************************************************************************"<<endl;
        cout<<"*        *********                                                                         *"<<endl;
        cout<<"*         *******                                                                          *"<<endl;
        cout<<"*          *****                                                                           *"<<endl;
        cout<<"*           ***                      Menu principal                                        *"<<endl;
        cout<<"*            **                   1--gestionar Cliente                                     *"<<endl;
        cout<<"*             *                   2--gestionar pedido                                      *"<<endl;
        cout<<"*             *                   3--Gestion de Menu                                    	  *"<<endl;        
        cout<<"*             *                   4--Venta del dia                                      	  *"<<endl;
        cout<<"*             *                   5--agregar empleado                                      *"<<endl;
        cout<<"*             *                   6--Info restaurante                                      *"<<endl;
        cout<<"*             *                   7--Salir                                      			  *"<<endl;
        
    	cout<<"*              *                     valor:";cin>>flujo;
        cout<<"*              *                                                                           *"<<endl;
        cout<<"*           ***                                                                            *"<<endl;
        cout<<"*          *                                                                               *"<<endl;
        cout<<"********************************************************************************************"<<endl;
        system("cls");

    
        switch(flujo){
    
        
        case 1: 
        system("cls");
        cout<<"********************************************************************************************"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                 ";Cliente();
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"********************************************************************************************"<<endl;
        break;
        
        case 2:
        system("cls");
        cout<<"********************************************************************************************"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                 ";Pedido();
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"********************************************************************************************"<<endl;
        break;
        case 3:gestionMenu(); break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: flujo=100; break;
        
       
    
        
        default:
        	cout<<"                	              *************************"<<endl;
       		cout<<"                               *   Valor Incorrecto    *"<<endl;
       		cout<<"                	              *************************"<<endl;
       		system("cls");
    }   

    }
    
    //return 0;
}






void Empleado(){	
    
    
	while(flujo!=100){
		system("cls");
		cout<<"          **    **                                                                         "<<endl;
        cout<<"*************  *****************************************************************************"<<endl;
        cout<<"*        *********                                                                         *"<<endl;
        cout<<"*         *******                                                                          *"<<endl;
        cout<<"*          *****                                                                           *"<<endl;
        cout<<"*           ***                      Menu principal                                        *"<<endl;
        cout<<"*            **                   1--gestionar Cliente                                     *"<<endl;
        cout<<"*             *                   2--gestionar pedido                                      *"<<endl;
        cout<<"*             *                   3--Salir                                                 *"<<endl;
    	cout<<"*              *                     valor:";cin>>flujo;
        cout<<"*              *                                                                           *"<<endl;
        cout<<"*           ***                                                                            *"<<endl;
        cout<<"*          *                                                                               *"<<endl;
        cout<<"********************************************************************************************"<<endl;
        system("cls");

    
    	switch(flujo){
        case 1: 
        system("cls");
        cout<<"********************************************************************************************"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                 ";Cliente();
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"********************************************************************************************"<<endl;
        break;
        
        case 2:
        system("cls");
        cout<<"********************************************************************************************"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                 ";Pedido();
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"*                                                                                          *"<<endl;
        cout<<"********************************************************************************************"<<endl;
        break;
        
        case 3: flujo=100; break;
        
        default:
        	
        
        	cout<<"                	              *************************"<<endl;
       		cout<<"                               *   Valor Incorrecto    *"<<endl;
       		cout<<"                	              *************************"<<endl;
       		Carga();
       		system("cls");
    }
    
}

	cout<<"                	                    *************************"<<endl;
	cout<<"                                     * Gracias, hasta luego. *"<<endl;
	cout<<"                	                    *************************"<<endl;

//	return 0;
}










void login(){
	
	
	while(flujo!=0){
		string usuario, contrasena;
        flujo=999;
	
		
		cout<<"                       Introduce tu usuario"<<endl;
		cout<<"                       ";cin>>usuario;
		cout<<"                       introudce tu contrasena"<<endl;
		cout<<"                       ";cin>>contrasena;		
		
		if(contrasena=="admin" && usuario=="admin"){
            cout<<"                	                    *************************"<<endl;
			Administrador();
            cout<<"                	                    *************************"<<endl;
		}
		else{cout<<"                	                    *************************"<<endl;
			Empleado();
            cout<<"                	                    *************************"<<endl;
		}
	}

    cout<<"                	                    *************************"<<endl;
	cout<<"                                     * Gracias, hasta luego. *"<<endl;
	cout<<"                	                    *************************"<<endl;


    system("pause");
}


int main(){

    login();

    return 0;
}















