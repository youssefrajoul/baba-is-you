# Baba is You
## Tareq "58600" and Youssef "59939
pour le cours de Dev4, groupe D121 
## Introduction 
Voici implémentation en c++ du Jeu "Baba is You" 
Dans cette itération le jeu est implémenté pour jouer dans le terminal

##  la structure de dépot 

```sh
├──  baba_is_you
│    └──.doc
│    └──controller
│    |  └──controller.h
│    |  └──controller.cpp
│    └──levels
│    |     └──(tous les fichier .txt ils représentent les niveaux de jeu)
│    └──test
│    |    └── (les fichier de tests)
│    └──view
│    |    └──view.h
│    |    └──view.cpp
│    └── (et tous les fichier du model)
├──  uml-analysis-diagram
│       └──Baba_is_You.mdj
│   
├── README
```


## les tests
pour executer les tests , le fichier main-console.cpp doit ressembler à ce-ci:

```sh
//#include "controller/controller.h"
#include "test/test.h"


int main()
{
    run_Tests();
    // Game game;
    //View view;
    //Controller controller = Controller(game, view);
    //controller.start();
    //return 0;
}
```

## Doxygen

Dans le dossier Baba_is_you vous trouverez un fichier Doxyfile qui permet de generer la doc en HTML. 
