#include <SFML/Graphics.hpp>
#include <iostream>
#define diziboyutu 1000

using namespace std;
int main(){
    srand(time(NULL));
             // Initialize SDL2
    int **dizi = new int*[diziboyutu];
    for(int i = 0 ; i < diziboyutu;i++){
        dizi[i] = new int[diziboyutu];
    }
    for(int i = 0 ; i < diziboyutu;i++){
        for(int j = 0; j < diziboyutu;j++){
            dizi[i][j] = 0;
        }
    }



int toplam =0;
int x,y;

    for(int i = 0 ; i <10000;i++){
        x=rand()%diziboyutu;
        y=rand()%diziboyutu;
        dizi[x][y]=1;
    }

    sf::RenderWindow(window);
    window.create(sf::VideoMode(diziboyutu, diziboyutu), "Hayat...");

    sf::Texture img;
    if(!img.loadFromFile("cell.bmp")) return 0;

    sf::Sprite sprite;
    sprite.setTexture(img);
    sprite.setPosition(100,100);
    int i = 0;

    sprite.setPosition(i,i);
    window.draw(sprite);
    window.display();
    //int a = 10;
    int c =diziboyutu/2;
dizi[c][c]=1;
dizi[c][c+1]=1;
dizi[c][c+2]=1;
dizi[c+1][c]=1;
dizi[c+2][c+1]=1;

while(window.isOpen())
{

    window.clear();
    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    std::cout<<mouse_pos.x<<" "<<mouse_pos.y<<"\n";
    x= mouse_pos.x;
    y = mouse_pos.y;


dizi[x][y]=1;
dizi[x][y+1]=1;
dizi[x][y+2]=1;
dizi[x+1][y]=1;
dizi[x+2][y+1]=1;





//sf::sleep(sf::seconds(0.5f));


for(int i = 1;i<diziboyutu-1;i++){
        for(int j = 1;j<diziboyutu-1;j++){

            if ((dizi[i][j+1] == 1)||(dizi[i][j+1] == -1)) toplam++;

            if ((dizi[i][j-1] == 1)||(dizi[i][j-1] == -1)) toplam++;

            if ((dizi[i+1][j] ==1)||(dizi[i+1][j] ==-1)) toplam++;

            if ((dizi[i+1][j-1] == 1)||(dizi[i+1][j-1] == -1)) toplam++;

            if ((dizi[i+1][j+1]==1)||(dizi[i+1][j+1]==-1))toplam++;

            if ((dizi[i-1][j] == 1)||(dizi[i-1][j] == -1)) toplam++;

            if ((dizi[i-1][j-1] == 1)||(dizi[i-1][j-1] == -1)) toplam++;

            if ((dizi[i-1][j+1]==1)||(dizi[i-1][j+1]==-1)) toplam++;


            if(((toplam > 3) || (toplam < 2)) && (dizi[i][j]==1)){
              dizi[i][j]=-1;
            }
            if((toplam == 3)&&(dizi[i][j]==0)){
                dizi[i][j] = 2;
            }

            toplam = 0;

        }
    }
    for(int i = 0;i < diziboyutu;i++){
        for(int j = 0;j<diziboyutu;j++){
            if(dizi[i][j]==-1){
                dizi[i][j]=0;
            }
            if(dizi[i][j]==2){
                dizi[i][j]=1;
            }
        }
    }



for(int i = 0;i < diziboyutu;i++){
        for(int j = 0; j < diziboyutu;j++){
            if((dizi[i][j] == 1)){
                sprite.setPosition(i,j);
                window.draw(sprite);
            }
    }
}



        window.display();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window.close();
        }
}

    return 0;
 }





