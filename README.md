# Ten Years Bunnies

<p style="text-align: center">
  <img src="https://raw.githubusercontent.com/aredhele33/Ten-Years-Bunnies/main/Press/000004_Ten_Years_Bunnies.gif" alt="Banner"/>
</p>

#### (Fr - English follows)
## En résumé
<p style="text-align: justify">
Cela fait maintenant bientôt 10 ans que j'ai commencé la programmation de jeux vidéo et je trouve que c'est
parfois intéressant d'avoir un regard et de prendre conscience des progrès que nous faisons ainsi que du chemin
parcouru. Je me suis alors souvenu de ce défi. Un simple programme dans lequel rebondissent des lapins par 
milliers.
</p>

## L'objectif

L'objectif de ce défi est assez simple, on ajoute des lapins tant que le framerate reste stable à 60 fps.
Jusqu'où pouvons-nous aller ?

## Compatibilité

Pour compiler ce programme sous Windows (uniquement), vous pouvez soit :
* Utiliser <a href="https://visualstudio.microsoft.com/fr/downloads/">Microsoft Visual Studio 2022</a> et ouvrir TenYearsBunnies.sln
* Utiliser <a href="https://www.jetbrains.com/fr-fr/clion/download/">CLion</a> (payant) et CMake en ouvrant le CMakeLists.txt

Note : Si vous utilisez CLion et CMake, pensez à utiliser la bonne version de MinGW que vous pourrez
télécharger 
<a href="https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z"> 
ici.
</a>

Le projet vient avec ses dépendances déjà compilées, il n'y a rien d'autre à faire.

## L'application

Pour rendre ce défi amusant, j'ai créé une application de base de la façon dont je l'aurais fait il y a 10 ans.
Il n'y a aucune optimisation et très peu de code. L'application elle-même est constituée de 10 fichiers :

<p style="text-align: center">
  <img src="https://raw.githubusercontent.com/aredhele33/Ten-Years-Bunnies/main/Press/000002_Ten_Years_Bunnies.png" alt="Banner"/>
</p>

Sans rentrer dans les détails :

| Fichier                  | Rôle                                     |
|--------------------------|------------------------------------------|
| Main.cpp                 | Point d'entrée du programme              |
| BunApplication.cpp       | Game loop, gestion du monde              |
| BunGameObjectBunny.cpp   | Objet du jeu représentant un lapin       |
| BunGameObjectManager.cpp | Objet du jeu permettant l'ajout de lapin |
| BunGameObjectTerrain.cpp | Objet du jeu affichant le terrain        |

## Contraintes

Cependant, ce challenge vient avec certaines contraintes :
* Le comportement des lapins doit rester inchangé;
* Le comportement du GameManager doit rester inchangé;
* On garde le smooth motion;
* Interdiction d'utiliser autre chose que la SFML pour le rendu.

#### (En)
## Abstract
<p style="text-align: justify">
I've been programming video games for almost 10 years now and I think it's sometimes interesting to take a
moment to observe where we are now, our progress and all the work behind us. I've remembered then that challenge.
A fairly simple program where thousands of bunnies are bouncing against the application boundaries, 
again and again.
</p>

## The goal

The goal of this challenge is simple, we keep adding bunnies as long as we keep a stable 60 fps.
How far can we go ?

## Compatibility

In order to compile this program under Windows (only), you can eiter :
* Use <a href="https://visualstudio.microsoft.com/fr/downloads/">Microsoft Visual Studio 2022</a> and open TenYearsBunnies.sln
* Use <a href="https://www.jetbrains.com/fr-fr/clion/download/">CLion</a> (not free) and CMake by opening the root CMakeLists.txt

Note : If you decide to use CLion and CMake, don't forget to use the right version of MinGW that you can download
<a href="https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z">
here
</a>
, otherwise, you will have linker errors.

## The application

To make this challenge interesting, I created this program as I would have created it 10 years ago.
There is no optimization and very few lines of code. The program itself is composed of 10 files :

<p style="text-align: center">
  <img src="https://raw.githubusercontent.com/aredhele33/Ten-Years-Bunnies/main/Press/000002_Ten_Years_Bunnies.png" alt="Banner"/>
</p>

Without going into details :

| Fichier                  | Rôle                                       |
|--------------------------|--------------------------------------------|
| Main.cpp                 | Program entry point                        |
| BunApplication.cpp       | Game loop, world management                |
| BunGameObjectBunny.cpp   | Game object used to control a single bunny |
| BunGameObjectManager.cpp | Game object used to add bunnies            |
| BunGameObjectTerrain.cpp | Game object used to display the terrain    |

## Constraints

However, this challenge comes with some constraints :
* You should not change the bunny's behavior;
* You should not change the GameManager's behavior;
* You should keep the smooth motion feature;
* You should not use something else that SFML for rendering;

---
* Windows 11 Pro
* i7-11700K
* RTX 3080 Ti

This is what I have with the base program (almost 100K, frustrating): 

<p style="text-align: center">
  <img src="https://raw.githubusercontent.com/aredhele33/Ten-Years-Bunnies/main/Press/000003_Ten_Years_Bunnies.png" alt="Banner"/>
</p>
