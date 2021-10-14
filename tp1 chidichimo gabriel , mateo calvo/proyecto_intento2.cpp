#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
using namespace sf;
using namespace std;

int main(){


	RenderWindow ventana(VideoMode(800, 600), "tp1"); //creacion de pantalla (videomode(resolucion) , "titulo"//
	
	RectangleShape shape(Vector2f(50.f, 100.f)); //tipo de forma/cuerpo y su tamaño//
	shape.setPosition(51.f, 0.f);
	shape.setFillColor(Color::Green); //color de la forma/ cuepo//
	
	RectangleShape forma(Vector2f(50.f, 100.f)); //tipo de forma/cuerpo y su tamaño//
	forma.setFillColor(Color::Red); //color de la forma/ cuepo//
	
	ventana.setFramerateLimit(30); //setea los fps de la ventana//

	int count=0;
	
	Font font;//inicializa la fuente
    if (!font.loadFromFile("Letritas.ttf")){}//carga la fuente
    Text text;//inicializa el texto
    text.setFont(font);//setea la fuente
    string colisiones = "Pulsa J para empezar";
    string contadorColisiones;
    text.setPosition(300.f , 0.f);//indica la posicion del texto
    text.setFillColor(sf::Color::Blue);    //indica que color sera el texto

	float empezo = false;//asta que no este en true no permite actualizar la pantalla
	
	while (ventana.isOpen()) //corre el programa mientras la ventana esta abierta
    {
    	// verifica todos los eventos de la ventana que se activaron desde la última iteración del ciclo
	    Event event;
	    while (ventana.pollEvent(event))
	    {
	    	// evento "cerrar solicitado": cerramos la ventana
            if (event.type == Event::Closed) 
            ventana.close(); 
		}
        ventana.clear();
		if (Keyboard::isKeyPressed(Keyboard::J)){//indica que tecla se tiene que precionar para que se cumpla la condicion
		shape.setPosition(0.f, 300.f); //indica la posicion de la figura/cuerpo//
		forma.setPosition(600.f, 300.f); //indica la posicion de la figura/cuerpo//
		empezo = true; //indica que comenzo el juego 
		colisiones = "Colisiones ";
		contadorColisiones= "0";
		}
		
		if (Keyboard::isKeyPressed(Keyboard::D) && empezo) //indica que tecla se tiene que precionar para que se cumpla la condicion
        {
            shape.move(10.f, 0.f); // si precionamos a se mueve a la derecha
            forma.setPosition(600.f, 300.f); //indica la posicion de la figura/cuerpo//
        }
        if (Keyboard::isKeyPressed(Keyboard::A)&& empezo) //indica que tecla se tiene que precionar para que se cumpla la condicion
        {
            shape.move(-10.f, 0.f); // si precionamos a se mueve a la izquierda
            forma.setPosition(600.f, 300.f); //indica la posicion de la figura/cuerpo//
        }
        if (Keyboard::isKeyPressed(Keyboard::S)&& empezo) //indica que tecla se tiene que precionar para que se cumpla la condicion
        {
            shape.move(0.f, 10.f); // si precionamos a se mueve arriba
            forma.setPosition(600.f, 300.f); //indica la posicion de la figura/cuerpo//
        }
        
        if (Keyboard::isKeyPressed(Keyboard::W)&& empezo) //indica que tecla se tiene que precionar para que se cumpla la condicion
        {
            shape.move(0.f, -10.f); // si precionamos a se mueve abajo
            forma.setPosition(600.f, 300.f); //indica la posicion de la figura/cuerpo//
        }
        
        FloatRect shape2 = shape.getGlobalBounds(); //crea hitbox de la forma nombrada
        FloatRect forma2 = forma.getGlobalBounds(); //crea hitbox de la forma nombrada
 
        if(shape2.intersects(forma2)){ //if que muestra la colicion//
        	forma.setFillColor(Color::Blue);//cambia el color de forma
        	forma.setOutlineThickness(-5.f);
            forma.setOutlineColor(sf::Color(130, 100, 90));
        	count++; 
        	stringstream ss;
			ss << count;
			contadorColisiones =  ss.str();
			
		}
        else{	
        	forma.setFillColor(Color::Red);//si no estta en colicion forma se mantiene en rojo
        	forma.setOutlineThickness(0.f);
		}
        

        
        if (Keyboard::isKeyPressed(Keyboard::P)) //indica que tecla se tiene que precionar para que se cumpla la condicion
        {
        	ventana.close(); //cierra la ventana
		}
	    

    
    text.setString(colisiones + contadorColisiones); //indica el texto que se va a escrivir     
    ventana.draw(text);
    ventana.draw(shape);
    ventana.draw(forma);
	ventana.display();	
	//ventana draw dibuja lo indicado en la pantalla
	//ventana display muestra la pantalla
    }
     	
	
    return 0;
 }
