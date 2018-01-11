#include <iostream>
#include <map>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

using namespace std;

int myrand(int a, int b)
{
    return a + random() % (b-a+1);
}

string nomBateau()
{
    string nomBateau;
    switch (getpid()%7){
    case 0:
        nomBateau = "La Teste de Buch";
        break;
    case 1:
        nomBateau = "Bordeaux";
        break;
    case 2:
        nomBateau = "Villenave d'Ornon";
        break;
    case 3:
        nomBateau = "Talence";
        break;
    case 4:
        nomBateau = "Pessac";
        break;
    case 5:
        nomBateau = "Gradignan";
        break;
    case 6:
        nomBateau = "Arcachon";
        break;
    }
    return nomBateau;
}

int main(int argc, char *argv[])
{
    for (int j=1 ; j<7 ; j++)
    {
        pid_t p = fork();
        srandom(getpid());
        if (p == 0) {
            for (int j=1 ; j<=4 ; j++)
            {
                cout << "le bateau de " << nomBateau() << " est parti" << endl;
                PosX += myrand(1,4);
                PosY += myrand(1,4);

                sleep(myrand(1,3));
            }

            int status;
            pid_t p = wait(&status);
            if (!WEXITSTATUS(status))
                cout << "le bateau de " << nomBateau() << " est arrivé !"<< endl;
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}
