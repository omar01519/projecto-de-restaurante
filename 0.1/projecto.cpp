#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include <locale.h> //Libreria para caracteres y acentos
using namespace std;

int flujo=999;


void Carga(){
	for (int i=0; i<=100; i++){
			system("cls");
		cout<<"                               [1]. Agregar otro"<<endl;
		cout<<"                               [2]. Para salir"<<endl;
		cin>>flujo;
		
		switch(flujo){
			
			case 1:continue; break;
			case 2: break;
			default: cout<<"                 Valor incorrecto."<<endl;
		}
	
	}	
}

void addtoMenu(){
	setlocale(LC_CTYPE,"Spanish");
	
	while(flujo==2){
		system("cls");
		ofstream archivo;
		archivo.open("Menucomida.txt",ios::out | ios::app);
		char nombrePlato[20];
		int precioPlato, idPlato;
	
		cout<<"                             Introduce los datos solicitados del men�."<<endl;
	
		if(archivo.fail()){
		cout<<"                               No se pudo crear el archivo."<<endl;
		//exit(1);
		}
	
		cout<<"                                  Id del plato"<<endl;
		cout<<"                                 "; cin>>idPlato;
		
		cout<<"                                  Nombre del plato"<<endl;
		
	
		cout<<"                                  Precio del Plato"<<endl;
		cout<<"                                  "; cin>>precioPlato; gets(nombrePlato);
		
		archivo<<idPlato<<" "<<precioPlato<<" "<<nombrePlato<<endl;
		archivo.close();
	
		system("cls");
	
		cout<<"El plato fue a�adido con exito."<<endl;

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
		cout<<"No se encontro dato para filtrar."<<endl;
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
	setlocale(LC_CTYPE,"Spanish");
	system("cls");
	
	int idClient=autoIdclient();
	
	
	ofstream archivo;
	archivo.open("cliente.txt",ios::out | ios::app);
	string nombreClient, apellidoClient, contactoClient;
	
	cout<<"                                Introduce los datos del usuario."<<endl;
	
	if(archivo.fail()){
		cout<<"                            No se pudo crear el archivo."<<endl;
		exit(1);
	}
	
	cout<<"                                  Nombre de Cliente"<<endl;
	cout<<"                                 "; cin>>nombreClient;
	
	cout<<"                                  Apellido de Cliente"<<endl;
	cout<<"                                 "; cin>>apellidoClient;
	
	cout<<"                                  N�mero telef�nico"<<endl;
	cout<<"                                  "; cin>>contactoClient;
	
	archivo<<idClient<<" "<<nombreClient<<" "<<apellidoClient<<" "<<contactoClient<<endl;
	archivo.close();
	
	system("cls");
	cout<<"Cliente guardado exitosamente."<<endl;
	system("pause");
}




string filtrarCliente(){
	setlocale(LC_CTYPE,"Spanish");
    string nombreClient, apellidoClient, contactoClient, idClient, filtro, filtro2;
	ifstream archivo;
	archivo.open("cliente.txt",ios::in);
	cout<<"									Introduce ID, Tel�fono, Nombre o Apellido."<<endl;
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
	setlocale(LC_CTYPE,"Spanish");
	
    while(flujo!=101){
        system("cls");
        cout<<" ************  **************************************************************************** "<<endl;
        cout<<"*        *********                  O & J FOOD                                             *"<<endl;
        cout<<"*         *******                   ==========                                             *"<<endl;
        cout<<"*          *****                   Gesti�n Men�                                            *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
        cout<<"*Gesti�n Administrador.                                                                    *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
	    cout<<"*                                 [1]. Ver Men�.                                           *"<<endl;
        cout<<"*                                 [2]. Agregar Plato.                                      *"<<endl;
        cout<<"*                                 [3]. Quitar Plato.                                       *"<<endl;
        cout<<"*                                 [4]. Modificar Plato.                                    *"<<endl;
        cout<<"*                                 [5]. Men� Principal.                                     *"<<endl;
        cout<<"*                                 [6]. Salir.                                              *"<<endl;
        cout<<"    Seleccione la opci�n deseada: ";cin>>flujo;
      
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


string getPedido(int filtro){
	string nomPlato, nameBack;
	int idPlato;
		
	
	ifstream archivo;
	archivo.open("Menucomida.txt",ios::in);
	
	if(archivo.fail()){
	cout<<"No se encontro dato para filtrar."<<endl;
	//exit(1);
	}
	
    
	while(!archivo.eof()){
	archivo>>idPlato;
    getline (archivo,nomPlato);
        
    if(idPlato==filtro){
        nameBack=nomPlato;
		}
		else if(!idPlato){
			break;
		}
        //cout<<idClient<<" "<<nomClient<<" "<<apellClient<<telClient<<endl;
	}
	
	return nameBack;
};




int numOrden(){
	string mesa;
	int numOrden;	
	
	//cout<<"test";
	
	ifstream archivo;
	archivo.open("Ordenes.txt",ios::in);	

	if(archivo.fail()){
		cout<<"No se encontr� dato para filtrar."<<endl;
		//exit(1);
	}
	
    
	while(!archivo.eof()){
        archivo>>numOrden;
        getline(archivo,mesa);
        
        //cout<<numOrden<<" "<<mesa<<endl;
	}
	
	numOrden=numOrden+1;
	cout<<numOrden;

	return numOrden;
}




string getClient(int filtro){
	string nomClient, apellClient, telClient, nameBack;
	int idClient;

		
	
	ifstream archivo;
	archivo.open("cliente.txt",ios::in);
	

	if(archivo.fail()){
		cout<<"No se encontr� dato para filtrar."<<endl;
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
		else if(!idClient){
			break;
		}
        //cout<<idClient<<" "<<nomClient<<" "<<apellClient<<telClient<<endl;
	}
	

	
	

	return nameBack;

}




string numeroMesa(int mesa){ 
	string numeroMesa;
	
	switch(mesa){
		case 1: numeroMesa="Mesa1"; break;
		case 2: numeroMesa="Mesa2"; break;
		case 3: numeroMesa="Mesa3"; break;
		case 4: numeroMesa="Mesa4"; break;
		case 5: numeroMesa="Mesa5"; break;
		case 6: numeroMesa="Mesa6"; break;
		case 7: numeroMesa="Mesa7"; break;
		case 8: numeroMesa="Mesa8"; break;
		case 9: numeroMesa="Mesa9"; break;
		case 10: numeroMesa="Mesa10"; break;
		case 11: numeroMesa="Mesa11"; break;
		case 12: numeroMesa="Mesa12"; break;
		case 13: numeroMesa="Mesa13"; break;
		case 14: numeroMesa="Mesa14"; break;
		case 15: numeroMesa="Mesa15"; break;
		case 16: numeroMesa="Mesa16"; break;
		case 17: numeroMesa="Mesa17"; break;
		default:  return 0; //cout<<" No tenemos ese numero de mesa habilitado actualmente"endl;
	}
	
	return numeroMesa;
}


void ponerOrden(){
	int mesa, numPedido, idClient, idPlato;
	string valorMesa, nomClient, nomPlato; 



	setlocale(LC_CTYPE,"Spanish");
		system("cls");
	
	ofstream archivo;
	archivo.open("Ordenes.txt",ios::out | ios::app);
	
	//getHorapedido();
	
	cout<<"         Selecciona el n�mero de mesa a la cu�l asignar�s la orden (1 al 17)"<<endl;
	cout<<"                                   ";cin>>mesa;
	valorMesa=numeroMesa(mesa);//para colocar orden en una mesa
	
	while(nomClient==""){
	
		cout<<"                                   Introduce el ID Del Cliente"<<endl;
		cout<<"                                   "; cin>>idClient;
		nomClient=getClient(idClient);//para colocar el nombre y el id del cliente
	
		if(nomClient==""){
			cout<<"                               No existe, busca el correcto."<<endl;
		}
	
	}
	
	
	while(nomPlato==""){
		
		cout<<"                                   Coloca el pedido solicitado"<<endl;
		cout<<"                                   "; cin>>idPlato;
		nomPlato=getPedido(idPlato);
		

		if(nomPlato==""){
			cout<<"                               Este plato no existe."<<endl;
		}
	}

numPedido=numOrden();//para conseguir el numero de pedido
	
	if(archivo.fail()){
		cout<<"                               No se pudo crear el archivo."<<endl;
		exit(1);
	}
	
	archivo<<numPedido<<" "<<valorMesa<<" "<<idClient<<" "<<nomClient<<" "<<idPlato<<" "<<nomPlato<<"\n";
	archivo.close();
	system("pause");

}



void Cliente(){
	setlocale(LC_CTYPE,"Spanish");

while(flujo!=101){
        system("cls");
        cout<<" ************  **************************************************************************** "<<endl;
        cout<<"*        *********                  O & J FOOD                                             *"<<endl;
        cout<<"*         *******                   ==========                                             *"<<endl;
        cout<<"*          *****                   Men� Clientes                                           *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
        cout<<"*Gesti�n Administrador.                                                                    *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
	    cout<<"*                             [1]. Agregar Clientes.                                       *"<<endl;
        cout<<"*                             [2]. Actualizar Clientes.                                    *"<<endl;
        cout<<"*                             [3]. Filtrar Clientes.                                       *"<<endl;
        cout<<"*                             [4]. Eliminar.                                               *"<<endl;
        cout<<"*                             [5]. Men� Principal.                                         *"<<endl;
        cout<<"*                             [6]. Salir.                                                  *"<<endl;
		cout<<"Seleccione la opci�n deseada: ";cin>>flujo;
      
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
	system("cls");
}

void Pedido(){
	
	setlocale(LC_CTYPE,"Spanish");
    while(flujo!=101){
    	system("cls");
        cout<<" ************  **************************************************************************** "<<endl;
        cout<<"*        *********                  O & J FOOD                                             *"<<endl;
        cout<<"*         *******                   ==========                                             *"<<endl;
        cout<<"*          *****                   Men� Pedidos                                            *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
        cout<<"*Gesti�n Administrador.                                                                    *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
		cout<<"*                            [1]. Agregar Orden                                            *"<<endl;
		cout<<"*                            [2]. IDCliente                                                *"<<endl;
		cout<<"*                            [3]. Men� de Comida                                           *"<<endl;
		cout<<"*                            [4]. Factura.                                                 *"<<endl;
		cout<<"*                            [6]. Actualizar pedido                                        *"<<endl;
		cout<<"*                            [7]. Eliminar pedido                                          *"<<endl;
		cout<<"*                            [8]. Volver al men� principal                                 *"<<endl;
		cout<<"*                            [9]. Men� principal                                           *"<<endl;
		cout<<"*                            [10]. Salir.                                                   *"<<endl;
		cout<<"Seleccione la opci�n deseada: ";cin>>flujo;
    
    	switch(flujo){
        	case 1: ponerOrden(); break;
          
        	case 2:break;
        
        	case 3:break;
          
        	case 4:break;
          
        	case 5:break;
        
        	case 6:break;
        
        	case 7:break;
        	
        	case 8:break;
        
        	case 9: flujo=101 ;break;

        	case 10: flujo= 100;break;
        
        	default:
        	cout<<"                              Valor Incorrecto"<<endl;
    	}

        if(flujo==100) break;

    }  
}


void Administrador(){	
    setlocale(LC_CTYPE,"Spanish");
    
    while(flujo!=100){
		system("cls");
		cout<<"          **    **                                                                          "<<endl;
        cout<<" ************  **************************************************************************** "<<endl;
        cout<<"*        *********                  O & J FOOD                                             *"<<endl;
        cout<<"*         *******                   ==========                                             *"<<endl;
        cout<<"*          *****                  Men� Principal                                           *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
        cout<<"*Gesti�n Administrador.                                                                    *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
        cout<<"*            **               [1]. Gestionar Cliente.                                      *"<<endl;
        cout<<"*             *               [2]. Gestionar Pedido.                                       *"<<endl;
        cout<<"*             *               [3]. Gesti�n de Men�.                                        *"<<endl;        
        cout<<"*             *               [4]. Venta del d�a.                                          *"<<endl;
        cout<<"*             *               [5]. Agregar Empleado.                                       *"<<endl;
        cout<<"*             *               [6]. Info Restaurante.                                       *"<<endl;
        cout<<"*             *               [7]. Salir.                                                  *"<<endl;
    	cout<<"*Seleccione la opci�n deseada: ";cin>>flujo;
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
    setlocale(LC_CTYPE,"Spanish");
    
	while(flujo!=100){
		system("cls");
		cout<<"          **    **                                                                          "<<endl;
        cout<<" ************  **************************************************************************** "<<endl;
        cout<<"*        *********                  O & J FOOD                                             *"<<endl;
        cout<<"*         *******                   ==========                                             *"<<endl;
        cout<<"*          *****                  Men� Principal                                           *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
        cout<<"*Gesti�n Empleado.                                                                         *"<<endl;
        cout<<"*------------------------------------------------------------------------------------------*"<<endl;
        cout<<"*                              [1]. Gestionar Cliente.                                     *"<<endl;
        cout<<"*                              [2]. Gestionar Pedido.                                      *"<<endl;
        cout<<"*                              [3]. Salir.                                                 *"<<endl;
    	cout<<"*    Seleccione la opci�n deseada: ";cin>>flujo	;
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
	setlocale(LC_CTYPE,"Spanish");
	
	while(flujo!=0){
		string usuario, contrasena;
		system("cls");
        flujo=999;
        cout<<" ************  *****************************************************************************"<<endl;
        cout<<"*        *********                     O & J FOOD                                           *"<<endl;
        cout<<"*         *******           Desayunos, Almuerzos y Aperitivos.                              *"<<endl;
        cout<<"*          *****    Copyright 2022 | Algoritmo y estructura de datos.                       *"<<endl;
        cout<<"*********************************************************************************************"<<endl;
        cout<<"*Iniciar Secci�n.                                                  by:2019-1416 & 2015-1666 *"<<endl;
        cout<<"*===========================================================================================*"<<endl;
        cout<<"==>Para acceder a la plataforma, ingresa las credenciales:"<<endl;
		cout<<"          Introduzca el nombre de usuario"<<endl;
		cout<<"        =>";cin>>usuario;
		cout<<"          Introduzca la contrase�a"<<endl;
		cout<<"        =>";cin>>contrasena;		
		
		if(contrasena=="admin" && usuario=="admin"){
            cout<<"                	                    *************************a"<<endl;
			Administrador();
            cout<<"                	                    *************************a"<<endl;
		}
		else{cout<<"                	                 *************************e"<<endl;
			Empleado();
            cout<<"                	                     *************************e"<<endl;
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
