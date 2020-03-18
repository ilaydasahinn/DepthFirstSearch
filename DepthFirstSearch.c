#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
//Dizimizi tuttuğumuz array
int Array[6][6];
//ziyaret edilme durumlarını tuttuğumuz array
bool visited[6];
 
//recursice DFS kodu
void DFS(int root, bool visited[])
{
    int i;
    //başlangıç düğümünü ziyaret edildi olarak işaretliyoruz.
    visited[root] = true;
    printf("%d ", root);
 
    for( i = 0; i < 6; i++)
    {
        //Eğer düğüm ziyaret edilmediyse her düğümün komşusunu 
        //Yeni başlangıç noktasıymış gibi tekrar çağırıyoruz
        if(Array[root][i] == 1 && visited[i] == false)
        {
            DFS(i, visited);
        }
    }
}
 
//matris dosyamızı okuyup diziye aktaran fonksiyon
void readMatrix()
{
    int i = 0;
    FILE *fp = fopen("matris.txt", "r");
 
    while(fscanf(fp, "%d %d %d %d %d %d",
                 &Array[i][0],
                 &Array[i][1],
                 &Array[i][2],
                 &Array[i][3],
                 &Array[i][4],
                 &Array[i][5]
                 ) != EOF)
    {
        i = i + 1 ;
    }
}
 
 
int main()
{
 
    readMatrix();
    DFS(0, visited);
    return 0;
}
